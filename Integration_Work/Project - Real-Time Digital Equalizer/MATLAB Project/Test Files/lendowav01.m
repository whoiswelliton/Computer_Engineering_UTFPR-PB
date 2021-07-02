[y,Fs] = audioread('Welliton - New Wave.wav');
plot(y);
sampleRate = 48e3;

loudness = integratedLoudness(y,sampleRate) %%Measure integrated loudness and loudness range