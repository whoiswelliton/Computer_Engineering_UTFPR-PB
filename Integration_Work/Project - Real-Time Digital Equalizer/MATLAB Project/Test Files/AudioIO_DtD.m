%% Real-Time Audio Stream Processing
%
% The Audio System Toolbox provides real-time, low-latency processing of
% audio signals using the System objects audioDeviceReader and
% audioDeviceWriter.
%
% This example shows how to acquire an audio signal using your microphone,
% perform basic signal processing, and play back your processed
% signal.
%

%% Create input and output objects
deviceReader = audioDeviceReader();
deviceWriter = audioDeviceWriter('SampleRate',deviceReader.SampleRate);

%% Specify an audio processing algorithm
% For simplicity, only add gain.
process = @(x) x.*5;

%% Code for stream processing
% Place the following steps in a while loop for continuous stream
% processing:
%   1. Call your audio device reader with no arguments to
%   acquire one input frame. 
%   2. Perform your signal processing operation on the input frame.
%   3. Call your audio device writer with the processed
%   frame as an argument.

disp('Begin Signal Input...')
tic
while toc<20
    mySignal = deviceReader();
    myProcessedSignal = process(mySignal);
    deviceWriter(myProcessedSignal);
end
disp('End Signal Input')

release(deviceReader)
release(deviceWriter)