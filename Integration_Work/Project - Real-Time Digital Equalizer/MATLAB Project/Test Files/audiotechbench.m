%%audioTestBench

asiosettings
deviceReader = audioDeviceReader;
devicesIN = getAudioDevices(deviceReader)
devicesOUT = getAudioDevices(deviceWriter)

%% interface utilizada para captura do sinal de áudio a partir de um arquivo ou dsp
%% pode gravar o sinal em arquivo ou mandar para uma saída de áudio
%% tem funcionalidades como time scope e spectrum scope
