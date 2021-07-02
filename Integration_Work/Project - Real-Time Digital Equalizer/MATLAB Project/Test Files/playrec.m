
SamplesPerFrame = 1024; %Quantidade de Amostras por Frame
Fs = 44100; %Frequência de Amostragem
playRec = audioPlayerRecorder('Device', 'Default','SampleRate', Fs, 'BufferSize', 1024)

% setpref('dsp', 'portaudioHostApi', 3);
% deviceReader = audioDeviceReader('Driver', 'ASIO', 'Device', 'ASIO4ALL v2', 'SamplesPerFrame', 1024, 'SampleRate', Fs);
% deviceWriter = audioDeviceWriter('Driver', 'ASIO', 'Device', 'ASIO4ALL v2', 'SampleRate', Fs, 'BufferSize', 1024);


SpectrumScope = dsp.SpectrumAnalyzer('SampleRate',Fs,'NumInputPorts',2,'PlotAsTwoSidedSpectrum',false,'ChannelNames',{'Entrada','Saída'},'ShowLegend',true);
show(SpectrumScope);
[audioFromDevice,numUnderrun,numOverrun] = playRec(audioToDevice)
SpectrumScope(audioFromDevice, audioToDevice);

%TimeScope = dsp.TimeScope('SampleRate',Fs);
%show(TimeScope);
process = @(x) x.*5; 

%%plot(abs(fft(mySignal)))
release(playRec)