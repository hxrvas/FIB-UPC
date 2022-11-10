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

    [labels, n] = bwlabel(bin);
    props = regionprops(labels, 'BoundingBox');
    imshow(labels, []), colormap colorcube
    pause

    bboxs = cat(1, props.BoundingBox);
    ratios = boundingboxratios(bboxs);
    widths = boundingboxwidths(bboxs);
    condition = ratios >= 2.5 & ratios <= 6 & widths > 0.028*w & widths < 0.145*w;
    candidates = bboxs(condition, :, :, :);
    sz = size(candidates);
    if sz > 0 
        colors = ['m', 'g', 'c', 'y', 'b', 'r', 'w', 'b','m', 'g', 'c', 'y', 'b', 'r', 'w', 'b''m', 'g', 'c', 'y', 'b', 'r', 'w', 'b''m', 'g', 'c', 'y', 'b', 'r', 'w', 'b''m', 'g', 'c', 'y', 'b', 'r', 'w', 'b'];
        imshow(I);
        hold on
        for j = 1:sz
            bbox = candidates(j, :, :, :);
            rectangle('Position',bbox,'EdgeColor',colors(j))
        end
        hold off
        drawnow
        pause
    end
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
