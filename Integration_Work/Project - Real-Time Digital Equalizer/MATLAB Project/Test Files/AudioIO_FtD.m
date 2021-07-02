%% Real-Time Audio Stream Processing
%
% The Audio System Toolbox provides real-time, low-latency processing of
% audio signals using the System objects dsp.AudioFileReader and
% audioDeviceWriter.
%
% This example shows how to acquire an audio signal using
% dsp.AudioFileReader, perform basic signal processing, and play your
% processed signal using audioDeviceWriter.
%

%% Create input and output objects
% Use the sample rate of your input as the sample rate of your output.
fileReader = dsp.AudioFileReader('speech_dft.mp3');
deviceWriter = audioDeviceWriter('SampleRate',fileReader.SampleRate);

%% Specify an audio processing algorithm
% For simplicity, only add gain.
process = @(x) x.*5;

%% Code for stream processing
% Place the following steps in a while loop for continuous stream
% processing until dsp.AudioFileReader is done reading the file:
%   1. Call your audio file reader with no arguments to
%   read one input frame.
%   2. Perform your signal processing operation on the input frame. 
%   3. Call your audio device writer with the processed
%   frame as an argument.

while ~isDone(fileReader)
    mySignal = fileReader();
    myProcessedSignal = process(mySignal);
    deviceWriter(myProcessedSignal);
end

release(fileReader)
release(deviceWriter)