%% Short Project
close all
a = dir('day_color(small sample)\*.jpg');
nf = size(a);
figure
for i = 1:nf 
    filename = horzcat(a(i).folder,'/',a(i).name);
    name = a(i).name;
    I = imread(filename);
    [~, w] = size(I);
    gray = rgb2gray(I); 
    bin = platebin(gray);
    
    candidates = platecandidates(bin, w);
    lookforplate(I, gray, candidates, name)
    pause
end 

%%
name = 'IMG_0415.jpg';
I = imread(name);
[h, w] = size(I);
gray = rgb2gray(I);
bin = platebin(gray);

candidates = platecandidates(bin, w);
lookforplate(I, gray, candidates, name)

%%
function res = platebin(im)
    clearborder = imclearborder(im);
    norm = mat2gray(clearborder);
    bin = imbinarize(norm);
    mark = imopen(bin, strel('disk', 5));
    res = imreconstruct(mark, bin);
end

function candidates = platecandidates(bin, w)
    [labels, ~] = bwlabel(bin);
    props = regionprops(labels, 'BoundingBox');
    bboxs = cat(1, props.BoundingBox);
    ratios = boundingboxratios(bboxs);
    widths = boundingboxwidths(bboxs);
    condition = ratios >= 2.5 & ratios <= 6 & widths > 0.04*w & widths < 0.14*w;
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
    plate = imcomplement(plate);
    plate = imbinarize(adapthisteq(plate));
    plate = blackborder(plate);
    if w > 235
        plate = imerode(plate, strel('disk',1));
    end
    [labels, ~] = bwlabel(plate, 4);
    %figure, imshow(labels, []), colormap colorcube;
    props = regionprops(labels, 'BoundingBox');
    bboxs = cat(1, props.BoundingBox);
    heights = boundingboxheights(bboxs);
    widths = boundingboxwidths(bboxs);
    condition = heights >= 0.4*h & widths <= 0.25 * w;
    candidates = bboxs(condition, :, :, :);
    [sz, ~] = size(candidates);
    if sz >= 7
        digits = candidates;
    else
        [labels, ~] = bwlabel(plate, 8);
        %figure, imshow(labels, []), colormap colorcube;
        props = regionprops(labels, 'BoundingBox');
        bboxs = cat(1, props.BoundingBox);
        heights = boundingboxheights(bboxs);
        widths = boundingboxwidths(bboxs);
        [h, w] = size(plate);
        condition = heights >= 0.4*h & widths <= 0.25 * w;
        digits = bboxs(condition, :, :, :);
    end
end


function result = isaplate(plate)
    digits = platedigits(plate);
    [sz, ~] = size(digits);
    %disp(sz)
    if sz >= 7
        result = true;
    else 
        result = false;
    end
end

function lookforplate(I, gray, candidates, name)
    [sz, ~] = size(candidates);
    if sz > 0
        for i = 1:sz
            bbox = candidates(i, :, :, :);
            plate = imcrop(gray, bbox);
            if isaplate(plate)
                digits = platedigits(plate);
                [n, ~] = size(digits);
                imshow(I), title(name);
                hold on
                rectangle('Position',bbox,'EdgeColor','y')
                for j = 1:n
                    digit = digits(j, :, :, :);
                    digit(1) = digit(1) + bbox(1);
                    digit(2) = digit(2) + bbox(2);
                    rectangle('Position',digit,'EdgeColor','g')
                end
                hold off
                break
            elseif i == sz
                disp("NO PLATE FOUND IN IMAGE "+name)
            end
        end
    else
        disp("NO CANDIDATES FOUND IN IMAGE "+name)
    end
end

function im = blackborder(im)
    [n, m] = size(im);
    im(1 , :) = 0;
    im(n, :) = 0;
    im(:, 1) = 0;
    im(:, m) = 0;
end

