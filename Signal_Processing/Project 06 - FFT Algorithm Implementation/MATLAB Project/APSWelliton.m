%%
% NAME: SOUMYA P.PANDA ROLL: 1304082 
%DECIMATION IN TIME [DIT] ALGORITHM

 % example : FFT_DIT_R2([1 2 3 4 5 ])

fs = 10000;
t = -1:1/fs:1;
x = tripuls(t,20e-3);
%x2 = rectpuls(t,20e-3);
%subplot(2,1,1)
plot(t,x1)
axis([-0.1 0.1 -0.2 1.2])
xlabel('Time (sec)')
ylabel('Amplitude')
title('Triangular Aperiodic Pulse')
                                                              

figure  
subplot(2,1,2);
plot(t,abs(j));
axis([-0.1 0.1 -0.2 1.2]);
%subplot(2,1,2);
%plot(t1,angle(x));

function e = dit(x)
t = nextpow2(length(x));             % round to next highest power of 2 because radix-2
j = [x zeros(1,(2^t)-length(x))] ;   % zero padding
N = length(j);                       % calculate length of padded sequence
S = log2(N);                         % no. of stages
j = bitrevorder(j);                  % bit-reverse the input sequence

for stage = 1:S   
    a = 1;                           % Initialise a and b, start points of the butterfly for each stage
    b = 1+2^(stage-1);
    n = 0;
       while( n<=2^(stage-1)-1 && b<=N)
        e = exp((-1i)*2*pi*n/(2^stage));    % Incorporate the twiddle factor
        y=j(a)+e*j(b);                    % Butterfly structure
        z=j(a)-e*j(b);
        j(a)=y;
        j(b)=z;
        a=a+1;
        b=b+1;     %  Increment a and b and n for the next butterfly structure
        n=n+1;
        
        if(rem(b,2^stage) == 1)
          a = a+2^(stage-1);      % Discontinuity of butterfly struc, change a,b and n
          b = b+2^(stage-1);
          n = 0;
        end
       end 
     
 end   
disp(j)
e=j;
end       