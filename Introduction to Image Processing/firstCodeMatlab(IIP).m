clear all
close all
clc
color = imread ('C:\Users\muhammadzubair\OneDrive - Punjab Group of Colleges\Desktop\lena_color.tiff');   %image read
% subplot(3,3,1);
% imshow(I);
% title('original image');
figure(),
imshow(color);
%y1 = 3.5;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%% Optic Disc removal code %%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%extracting green component of RGB image
green_component = color(:, :, 2);
figure(),imshow(green_component)
% subplot(3,3,2);
% imshow(green_component);
% title('green component');

red_component = color(:, :, 1);
figure(), imshow(red_component);
%title('red compo')

blue_component = color(:, :, 3);

%Task convert to binary by setting threshold (0-128 = Black, 129-255 =
%White)


 
 
