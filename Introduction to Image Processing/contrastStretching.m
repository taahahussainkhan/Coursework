 color = imread('C:\Users\muhammadzubair\OneDrive - Punjab Group of Colleges\Desktop\lena_color.tiff');
 gray = rgb2gray(color);
 figure(), imshow(gray);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
coin = imread('coins.png');
% figure, subplot (3,3,1), imshow(coin), title('original')
% 
coin1 = bitget(coin,1);
imhist(coin1)
% subplot (3,3,2), imshow(logical(coin1)), title('1st bit')
% 
% coin2 = bitget(coin,2);
% subplot (3,3,3), imshow(logical(coin2)), title('2nd bit')
% 
% coin3 = bitget(coin,3);
% subplot (3,3,4), imshow(logical(coin3)), title('3rd bit')
% 
% coin4 = bitget(coin,4);
% subplot (3,3,5), imshow(logical(coin4)), title('4th bit')
% 
% coin5 = bitget(coin,5);
% subplot (3,3,6), imshow(logical(coin5)), title('5th bit')
% 
coin6 = bitget(coin,6);
imhist(coin6)
% subplot (3,3,7), imshow(logical(coin6)), title('6th bit')
% 
% coin7 = bitget(coin,7);
% subplot (3,3,8), imshow(logical(coin7)), title('7th bit')
% 
% coin8 = bitget(coin,8);
% subplot (3,3,9), imshow(logical(coin8)), title('8th bit')
% 
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% %%%%%%%%%%%%%%%%  image reconstruction  %%%%%%%%%%%%%%%%%%%%%
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
new1_coin=zeros(size(coin));
new1_coin=bitset(new1_coin,8,bitget(coin,8));
new1_coin=bitset(new1_coin,7,bitget(coin,7));
new1_coin=uint8(new1_coin);
figure, imshow(new1_coin);
% saveas(gcf, '8thand7thbitSlice.tiff');

imhist(gray)
J = imadjust(gray,stretchlim(gray),[]);
figure
imshow(J)

imhist(J)

