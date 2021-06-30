library ieee;
use ieee.std_logic_1164.all;

entity bin_gray is 
	
	port( b0, b1, b2, b3: in std_logic;
		   g0, g1, g2, g3: out std_logic);
end bin_gray;

architecture arq of bin_gray is
begin 
g3 <= b3;
g2 <= b3 xor b2;
g1 <= b2 xor b1;
g0 <= b1 xor b0;
end arq;
