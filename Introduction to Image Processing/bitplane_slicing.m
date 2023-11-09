color = imread('C:\Users\muhammadzubair\Desktop\shortImg.jpeg');
gray = rgb2gray(color);
gray1 = bitget(gray,1);
gray2 = bitget(gray,2);
gray3 = bitget(gray,3);
gray4 = bitget(gray,4);
gray5 = bitget(gray,5);
gray6 = bitget(gray,6);
gray7 = bitget(gray,7);
gray8 = bitget(gray,8);

figure,
subplot(3,3,1), imshow(gray)
subplot(3,3,2), imshow(logical(gray1))
subplot(3,3,3), imshow(logical(gray2))
subplot(3,3,4), imshow(logical(gray3))
subplot(3,3,5), imshow(logical(gray4))
subplot(3,3,6), imshow(logical(gray5))
subplot(3,3,7), imshow(logical(gray6))
subplot(3,3,8), imshow(logical(gray7))
subplot(3,3,9), imshow(logical(gray8))


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
coin = imread('coins.png');
figure, subplot (3,3,1), imshow(coin), title('original')

coin1 = bitget(coin,1);
subplot (3,3,2), imshow(logical(coin1)), title('1st bit')

coin2 = bitget(coin,2);
subplot (3,3,3), imshow(logical(coin2)), title('2nd bit')

coin3 = bitget(coin,3);
subplot (3,3,4), imshow(logical(coin3)), title('3rd bit')

coin4 = bitget(coin,4);
subplot (3,3,5), imshow(logical(coin4)), title('4th bit')

coin5 = bitget(coin,5);
subplot (3,3,6), imshow(logical(coin5)), title('5th bit')

coin6 = bitget(coin,6);
subplot (3,3,7), imshow(logical(coin6)), title('6th bit')

coin7 = bitget(coin,7);
subplot (3,3,8), imshow(logical(coin7)), title('7th bit')

coin8 = bitget(coin,8);
subplot (3,3,9), imshow(logical(coin8)), title('8th bit')

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%  image reconstruction  %%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

new1_coin=zeros(size(coin));
new1_coin=bitset(new1_coin,8,bitget(coin,8));
new1_coin=bitset(new1_coin,7,bitget(coin,7));
new1_coin=uint8(new1_coin);
figure, imshow(new1_coin);
saveas(gcf, '8thand7thbitSlice.tiff');

