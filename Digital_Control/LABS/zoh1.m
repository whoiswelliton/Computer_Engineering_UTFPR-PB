N = length(y);

subplot(411)
Y = abs(fft(y,N))/N;
Y(2:N/2) = 2*Y(2:N/2);
f = 0:(length(Y)-1);
bar(f(1:N/2),Y(1:N/2))
title('y original')
subplot(412)
Y10 = abs(fft(y10,N))/N;
Y10(2:N/2) = 2*Y10(2:N/2);
bar(f(1:N/2),Y10(1:N/2))
title('y amostrado com 10 Hz')
subplot(413)
Y110 = abs(fft(y110,N))/N;
Y110(2:N/2) = 2*Y110(2:N/2);
bar(f(1:N/2),Y110(1:N/2))
title('y amostrado com 110 Hz')
subplot(414)
Y1000 = abs(fft(y1000,N))/N;
Y1000(2:N/2) = 2*Y1000(2:N/2);
bar(f(1:N/2),Y1000(1:N/2))
title('y amostrado com 1000 Hz')