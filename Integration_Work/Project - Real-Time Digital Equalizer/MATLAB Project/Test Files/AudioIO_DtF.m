%% Real-Time Audio Stream Processing
%
% The Audio System Toolbox provides real-time, low-latency processing of
% audio signals using the System objects audioDeviceReader and
% dsp.AudioFileWriter.
%
% This example shows how to acquire an audio signal using your microphone,
% perform basic signal processing, and write your signal to a file.
%

%% Create input and output objects
% Use the sample rate of your input as the sample rate of your output.
deviceReader = audioDeviceReader;
fileWriter = dsp.c('SampleRate',deviceReader.SampleRate);

%% Specify an audio processing algorithm
% For simplicity, only add gain.
process = @(x) x.*5;

%% Code for stream processing
% Place the following steps in a while loop for continuous stream
% processing:
%   1. Call your audio device reader with no arguments to
%   acquire one input frame. 
%   2. Perform your signal processing operation on the input frame. 
%   3. Call your audio file reader with the processed frame
%   as an argument.
%    	Note: The file is named 'output.wav' and written to current folder by default. 

disp('Begin Signal Input...')
tic
while toc<100
    mySignal = deviceReader();
    myProcessedSignal = process(mySignal);
    fileWriter(myProcessedSignal);
end
disp('End Signal Input')

release(deviceReader)
release(fileWriter)