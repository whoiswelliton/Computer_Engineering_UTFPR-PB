mididevinfo
setpref('midi','Minilab','Arturia MiniLab mkII');
initialControlValue = 0;

Minilab = mididevice('Input','Arturia MiniLab mkII')
MIDIControls = midicontrols();
midiread(MIDIControls)
%receivedMessages = midireceive(Minilab)
%[controlNumber,deviceName] = midiid;

