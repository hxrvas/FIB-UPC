%% Short Project
close all
a = dir('day_color(small sample)\*.jpg');
nf = size(a);
figure
for i = 1:nf 
    filename = horzcat(a(i).folder,'/',a(i).name);
    I = imread(filename);
    [h, w] = size(I);
    gray = rgb2gray(I);
    bin = platebin(gray);
    
    candidates = platecandidates(bin, w);
    lookforplate(gray, candidates)
    pause
end
%%
function res = platebin(im)
    clearborder = imclearborder(im);
    norm = mat2gray(clearborder);
    bin = imbinarize(norm);
    mark = imopen(bin, strel('disk', 5));
    rec = imreconstruct(mark, bin);
    rec = imerode(rec, 1);
    res = imerode(rec, 1);
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
    plate = imcomplement(plate);
    plate = imbinarize(plate);
    plate = imclearborder(plate);
    [labels, ~] = bwlabel(plate);
    props = regionprops(labels, 'BoundingBox');
    bboxs = cat(1, props.BoundingBox);
    heights = boundingboxheights(bboxs);
    [h, ~] = size(plate);
    digits = bboxs(heights >= 0.5*h, :, :, :);
end

function result = isaplate(plate)
    plate = imcomplement(plate);
    plate = imbinarize(plate);
    plate = imclearborder(plate);
    [labels, ~] = bwlabel(plate);
    props = regionprops(labels, 'BoundingBox');
    bboxs = cat(1, props.BoundingBox);
    heights = boundingboxheights(bboxs);
    [h, ~] = size(plate);
    digits = bboxs(heights >= 0.5*h, :, :, :);
    [sz, ~] = size(digits);
    if sz >= 7
        result = true;
    else 
        result = false;
    end
end

function lookforplate(im, candidates)
    [sz, ~] = size(candidates);
    if sz > 0
        for i = 1:sz
            bbox = candidates(i, :, :, :);
            plate = imcrop(im, bbox);
            if isaplate(plate)
                digits = platedigits(plate);
                [n, ~] = size(digits);
                imshow(plate);
                hold on
                for j = 1:n
                    bbox = digits(j, :, :, :);
                    rectangle('Position',bbox,'EdgeColor','g')
                end
                hold off
                break
            %else 
                %disp("NOT A PLATE")
            end
        end
    else
        disp("NO CANDIDATES FOUND")
    end
end

