model = 'ex_spectrumanalyzer_tut';
open_system(model)
open_system([model '/Digital Filter Design'])
sim(model)
open_system([model '/Spectrum Analyzer'])