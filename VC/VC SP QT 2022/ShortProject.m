%% SHORT PROJECT
% Joan Hervás and Óscar Estudillo

%% Goal
% The goal of this project is to implement code for the detection and
% reading of license plates in an image dataset of cars in exterior
% scenarios.

%% SHORT PROJECT
% Joan Hervás i Óscar Estudillo

%% Feature dictionaries
digitsDictionary = createDigitDictionary();
lettersDictionary = createLetterDictionary();
%% Train a classifier (no va no lo he mirado mucho)

%% Project
good = 0;
notfound = 0;
nocandidates = 0;

notfoundnames = string([]);
nocandidatesnames = string([]);

close all
%a = dir('VC SP QT 2022/day_color(small sample)\*.jpg');
a = dir('day_color(small sample)\*.jpg');
nf = size(a);
figure
for i = 1:nf 
    %Read image
    filename = horzcat(a(i).folder,'/',a(i).name);
    name = a(i).name;
    I = imread(filename);
    [~, w] = size(I);
    gray = rgb2gray(I); 
     
    %Preprocess Image
    bin = platebin(gray);
    
    %Extract Plate Candidates
    candidates = platecandidates(bin, w);
    [sz, ~] = size(candidates);
    if sz == 0
        bin = hardlightplatebin(gray);
        candidates = platecandidates(bin, w);
    end
    
    %Extract Digits
    [sz, ~] = size(candidates);
    if sz > 0
    
    [plate, digits] = lookforplate(gray, candidates, name);
    
    if length(digits) == 7 && isempty(plate) == 0
        %Extract Plate Features
        features = extractPlateFeatures(I, plate, digits);
    
        %Classify Plate Features
        stringPlate = findAndPrintPlateString(digitsDictionary, lettersDictionary, features);
    
        %Print result
        printImage(I, name, plate, digits, stringPlate);
        good = good + 1;
    else
        imshow(I), title(name + " has plate candidates");
        hold on
        for j = 1:sz
             bbox = candidates(j, :, :, :);
             rectangle('Position',bbox,'EdgeColor','y')
        end
        notfound = notfound + 1;
        notfoundnames = [notfoundnames, name];
    end
    
    else
        imshow(I), title(name + " has no plate candidates");
        nocandidates = nocandidates + 1;
        nocandidatesnames = [nocandidatesnames, name];
    end
    pause
end 

accuracy = good / nf(1);

%% Pruebas
digitsDictionary = createDigitDictionary();
lettersDictionary = createLetterDictionary();
%Read image
filename = "car2.jpg";
name = "Prueba";
%Read image
I = imread(filename);
[~, w] = size(I);
gray = rgb2gray(I); 
 
%Preprocess Image
bin = platebin(gray);

%Extract Plate Candidates
candidates = platecandidates(bin, w);
[sz, ~] = size(candidates);
if sz == 0
    disp("HARD LIGHT BIN")
    bin = hardlightplatebin(gray);
    candidates = platecandidates(bin, w);
end

%Extract Digits
[sz, ~] = size(candidates);
if sz > 0

[plate, digits] = lookforplate(gray, candidates, name);

if length(digits) == 7 && isempty(plate) == 0
    %Extract Plate Features
    features = extractPlateFeatures(I, plate, digits);

    %Classify Plate Features
    stringPlate = findAndPrintPlateString(digitsDictionary, lettersDictionary, features);

    %Print result
    printImage(I, name, plate, digits, stringPlate);
    
    
else
    figure, imshow(I), title(name + " has plate candidates");
    hold on
    for j = 1:sz
         bbox = candidates(j, :, :, :);
         rectangle('Position',bbox,'EdgeColor','y')
    end
end

else
    figure, imshow(I), title(name + " has no plate candidates");
end

%% Preprocessing Functions
function res = platebin(im)
    [h, w] = size(im);
    clearborder = imclearborder(im);
    norm = mat2gray(clearborder);
    bin = imbinarize(norm);
    area = h*w;
    min = 0.001*area;
    max = 0.15*area;
    filtered = bwareafilt(bin, [min max]);
    mark = imopen(filtered, strel('disk', 5));
    rec = imreconstruct(mark, bin);
    res = imerode(rec, strel('disk', double((int16(w*0.0005)))));
end

function res = hardlightplatebin(im)
    [h, w] = size(im);
    clearborder = imclearborder(imflatfield(im, 30));
    bin = imbinarize(clearborder,'adaptive', 'Sensitivity', 0.3);
    area = h*w;
    min = 0.005*area;
    max = 0.15*area;
    filtered = bwareafilt(bin, [min max]);
    mark = imopen(filtered, strel('disk', 5));
    rec = imreconstruct(mark, filtered);
    res = imerode(rec, strel('disk', double((int16(w*0.001)))));
end


%% Candidates Functions
function candidates = platecandidates(bin, w)
    [labels, ~] = bwlabel(bin);
    props = regionprops(labels, 'BoundingBox');
    bboxs = cat(1, props.BoundingBox);
    ratios = boundingboxratios(bboxs);
    widths = boundingboxwidths(bboxs);
    condition = ratios >= 2.5 & ratios <= 6 & widths > 0.03*w & widths < 0.14*w;
    candidates = bboxs(condition, :, :, :);
end

function ratios = boundingboxratios(bboxs)
    n = size(bboxs);
    ratios = zeros(n(1), 1);
    for i = 1:n
        bbox = bboxs(i, :, :, :);
        ratio = bbox(3) / bbox(4);
        ratios(i) = ratio;
    end
end

function widths = boundingboxwidths(bboxs)
    n = size(bboxs);
    widths = zeros(n(1), 1);
    for i = 1:n
        bbox = bboxs(i, :, :, :);
        width = bbox(3);
        widths(i) = width;
    end
end

function heights = boundingboxheights(bboxs)
    n = size(bboxs);
    heights = zeros(n(1), 1);
    for i = 1:n
        bbox = bboxs(i, :, :, :);
        height = bbox(4);
        heights(i) = height;
    end
end

function digits = platedigits(plate)
    [h, w] = size(plate);
    plate = imcomplement(mat2gray(plate));
    plate = imadjust(plate);
    plate = imbinarize(plate);
    bborder = blackborder(plate, int16(0.28*h), int16(0.07*w));
    plate = imreconstruct(bborder, plate);
    plate = blackborder(plate, int16(0.125*h), int16(0.035*w));
    platearea = h*w;
    min = 0.005*platearea;
    max = 0.1*platearea;
    filtered = bwareafilt(plate, [min max]);
    filtered = bwareafilt(filtered, 7);
    filtered = imreconstruct(filtered, plate);
    [labels, ~] = bwlabel(filtered, 8);
    props = regionprops(labels, 'BoundingBox');
    bboxs = cat(1, props.BoundingBox);
    heights = boundingboxheights(bboxs);
    widths = boundingboxwidths(bboxs);
    condition = heights >= 0.2*h & widths <= 0.3*w;
    dcandidates = bboxs(condition, :);
    [sz, ~] = size(dcandidates);
    if sz >= 7
        digits = dcandidates;
    else
        [labels, ~] = bwlabel(plate, 8);
        props = regionprops(labels, 'BoundingBox');
        bboxs = cat(1, props.BoundingBox);
        ratios = boundingboxratios(bboxs);
        heights = boundingboxheights(bboxs);
        widths = boundingboxwidths(bboxs);
        condition = heights >= 0.2*h & ratios <= 1.2 & widths <= 0.3*w;
        digits = bboxs(condition, :);
    end
end

function result = isaplate(plate)
    digits = platedigits(plate);
    [sz, ~] = size(digits);
    if sz >= 7
        result = true;
    else 
        result = false;
    end
end

function [plateRes, digitsRes] = lookforplate(gray, candidates, name)
    [sz, ~] = size(candidates);
    plateRes = zeros(0);
    digitsRes = zeros(0);
    if sz > 0
        for i = 1:sz
            bbox = candidates(i, :, :, :);
            plate = imcrop(gray, bbox);
            if isaplate(plate)
                digits = platedigits(plate);
                digitsRes=digits;
                plateRes=bbox;
                break
            end
        end
    end
end

function im = blackborder(im, height, width)
    [n, m] = size(im);

    im(1:1+double(height), :) = 0;
    im(double(n-height):n, :) = 0;
    im(:, 1:1+double(width)) = 0;
    im(:, double(m-width):m) = 0;
end


%% Feature match functions
function res = createDigitDictionary()
    numbersString = ["1","2","3","4","5","6","7","8","9","0"];
    I = rgb2gray(imread("Greek-License-Plate-Font-old.jpg"));
    bw = ~imbinarize(I);
    numbers = regionprops(bw,'BoundingBox');
    plateDictionary = containers.Map('KeyType','char','ValueType','any');
    
    for k = 1 : 10
      thisBB = numbers(k).BoundingBox;
      crop = imcrop(bw, thisBB);
      cropWithPadding = padarray(crop, [20,20], 0, "both");
      corners = detectSIFTFeatures(cropWithPadding);
      [features,~] = extractFeatures(cropWithPadding,corners);
      hold on;
      plateDictionary(numbersString(k)) = features;
    end
    
    res = plateDictionary;
end

function res = createLetterDictionary()
    numbersString = ["A","B","E","H","I","K","M","N","P","T","X","Y","Z"];
    I = rgb2gray(imread("Greek-License-Plate-Font-old.jpg"));
    bw = ~imbinarize(I);
    numbers = regionprops(bw,'BoundingBox');
    plateDictionary = containers.Map('KeyType','char','ValueType','any');
    
    for k = 12 : 24
      thisBB = numbers(k).BoundingBox;
      crop = imcrop(bw, thisBB);
      cropWithPadding = padarray(crop, [20,20], 0, "both");
      corners = detectSIFTFeatures(cropWithPadding);
      [features,~] = extractFeatures(cropWithPadding,corners);
      hold on;
      plateDictionary(numbersString(k-11)) = features;
    end

    res = plateDictionary;
end

function res = extractPlateFeatures(I, plate, digits)
    digitsFeatures = containers.Map('KeyType','double','ValueType','any');
    for k = 1 : length(digits)
           digit = digits(k, :);
           digit(1) = digit(1) + plate(1);
           digit(2) = digit(2) + plate(2);
           crop = imcrop(I, digit);
    
           grayIm=(255 - im2gray(crop+100));
           %figure, imshow(grayIm, []);
           bw=imbinarize(grayIm);
    
           cropWithPadding = padarray(bw, [20,20], 0, "both");
           %figure, imshow(cropWithPadding);
    
           corners = detectSIFTFeatures(cropWithPadding);
           [features,~] = extractFeatures(cropWithPadding,corners);
           %disp(features);
    
           digitsFeatures(k) = features;
    
           %figure, imshow(cropWithPadding);
           hold on;
           %plot(valid_corners);
    end
    res = digitsFeatures;
end

function res = findAndPrintPlateString(digitDictionary, letterDictionary, digitsFeatures)
    digitsString = ["1","2","3","4","5","6","7","8","9","0"];
    lettersString= ["A","B","E","H","I","K","M","N","P","T","X","Y","Z"];
    strongestMatch = cell(7,1);
    plateString = "";
    
    %Digits
    for k = 1 : 3
        maxMatchedFeatures = 0;
        %minMetricDistance = 100000000;
        for l = 1 : letterDictionary.length
            [indexPairs, matchMetric] = matchFeatures(digitsFeatures(k), letterDictionary(lettersString(l)));
            n = length(indexPairs);
            if (n > maxMatchedFeatures)
                %distance = sum(matchMetric)/n;
                %if (distance < minMetricDistance)
                    maxMatchedFeatures = n;
                    %minMetricDistance = distance;
                    strongestMatch{k} = lettersString(l);
                %end
            end
        end
        if (isempty(strongestMatch{k}))
            strongestMatch{k,1}="*";
        end
        plateString = strcat(plateString, strongestMatch{k});
    end
   
    plateString = strcat(plateString, "-");

    for k = 4 : 7
        maxMatchedFeatures = 0;
        %minMetricDistance = 100000000;
        for l = 1 : digitDictionary.length
            [indexPairs, matchMetric] = matchFeatures(digitsFeatures(k), digitDictionary(digitsString(l)));
            n = length(indexPairs);
            if (n > maxMatchedFeatures)
                %distance = sum(matchMetric)/n;
                %if (distance < minMetricDistance)
                    maxMatchedFeatures = n;
                    %minMetricDistance = distance;
                    strongestMatch{k} = digitsString(l);
                %end
            end
        end
        if (isempty(strongestMatch{k}))
            strongestMatch{k}="*";
        end
        plateString = strcat(plateString, strongestMatch{k});
    end
    res = plateString;
end

function printImage(I, name, plate, digits, plateString)
    [n, ~] = size(digits);
    imshow(I), title(name + " has plate: " + plateString);
    hold on
    rectangle('Position',plate,'EdgeColor','y')
    for j = 1:n
        digit = digits(j, :, :, :);
        digit(1) = digit(1) + plate(1);
        digit(2) = digit(2) + plate(2);
        rectangle('Position',digit,'EdgeColor','g')
    end
    hold off
end

%% Classifier functions (not used)
function res = createDigitClassifier()
    trainingLabels = ["1","2","3","4","5","6","7","8","9","0"];

    % Read image with all the digits
    I = rgb2gray(imread("Greek-License-Plate-Font-2004.svg.png"));
    bw = ~imbinarize(I);
    
    
    numbers = regionprops(bw,'BoundingBox');

    trainingFeatures = zeros(10, 7488, 'single');

    thisBB = numbers(1).BoundingBox;
    crop = imcrop(bw, thisBB);
    cropWithPadding = padarray(crop, [20,22], 0, "both");
    [featureVector, ~] = extractHOGFeatures(cropWithPadding, 'CellSize',[4 4]);
    trainingFeatures(1, :) = featureVector;  
    
    for i = 2 : 10
        thisBB = numbers(i).BoundingBox;
        crop = imcrop(bw, thisBB);
        cropWithPadding = padarray(crop, [20,20], 0, "both");
        [featureVector, ~] = extractHOGFeatures(cropWithPadding, 'CellSize',[4 4]);
        trainingFeatures(i, :) = featureVector;  
    end

    res = fitcecoc(trainingFeatures, trainingLabels);
end

function res = createLetterClassifier()
    
    trainingLabels = ["A","B","E","H","I","K","M","N","P","T","X","Y","Z"];
    
    % Read image with all the digits
    I = rgb2gray(imread("Greek-License-Plate-Font-2004.svg.png"));
    bw = ~imbinarize(I);
    
    
    numbers = regionprops(bw,'BoundingBox');
    
    trainingFeatures = zeros(13, 7488, 'single');
    
    for i = 1 : 4
        thisBB = numbers(i+11).BoundingBox;
        crop = imcrop(bw, thisBB);
        cropWithPadding = padarray(crop, [20,20], 0, "both");
        [featureVector, ~] = extractHOGFeatures(cropWithPadding, 'CellSize',[4 4]);
        trainingFeatures(i, :) = featureVector; 
    end
    
    thisBB = numbers(16).BoundingBox;
    crop = imcrop(bw, thisBB);
    cropWithPadding = padarray(crop, [20,26], 0, "both");
    [featureVector, ~] = extractHOGFeatures(cropWithPadding, 'CellSize',[4 4]);
    trainingFeatures(5, :) = featureVector; 
    
    for i = 6 : 13
        thisBB = numbers(i+11).BoundingBox;
        crop = imcrop(bw, thisBB);
        cropWithPadding = padarray(crop, [20,20], 0, "both");
        [featureVector, ~] = extractHOGFeatures(cropWithPadding, 'CellSize',[4 4]);
        trainingFeatures(i, :) = featureVector;  
    end
    
    res = fitcecoc(trainingFeatures, trainingLabels);
end



% NO VA IGNORAR POR AHORA
function res = extractPlateHOGFeatures(I, plate, digits)
    digitsFeatures = zeros(length(digits), 0, 0);
    for k = 1 : length(digits)
           digit = digits(k, :);
           digit(1) = digit(1) + plate(1);
           digit(2) = digit(2) + plate(2);
           crop = imcrop(I, digit);
    
           grayIm=(255 - im2gray(crop+100));
           %figure, imshow(grayIm, []);
           bw=imbinarize(grayIm);
    
           cropWithPadding = padarray(bw, [20,20], 0, "both");
           %figure, imshow(cropWithPadding);
    
           [features,~] = extractHOGFeatures(cropWithPadding, 'CellSize',[4 4]);
           %disp(features);
    
           digitsFeatures(k) = features;
    
           %figure, imshow(cropWithPadding);
           %plot(valid_corners);
    end
    res = digitsFeatures;
end

function res = findAndPrintPlateStringClassifier(digitClassifier, letterClassifier, digitsFeatures)
    plateString = "";
    %Letters
    for i = 1:3
        predictedLabel = predict(letterClassifier, digitsFeatures(i));
        plateString = strcat(plateString, predictedLabel);
    end
    plateString = strcat(plateString, "-");
    %Digits
    for i = 4:7
        predictedLabel = predict(digitClassifier, digitsFeatures(i));
        plateString = strcat(plateString, predictedLabel);
    end

    res = plateString;
end



