library ieee;
use ieee.std_logic_1164.all;

entity mux is
port (a0,a1,a2,i0,i1,i2,i3,i4,i5,i6,i7: in std_logic;
		y: out std_logic);
end mux;

architecture arq of mux is
	signal s0, s1, s2, s3, s4, s5, s6, s7: std_logic;
begin

	y <= s0 or s1 or s2 or s3 or s4 or s5 or s6 or s7;
	
	s0 <= a0 and a1 and a2 and i7;
	s1 <= not(a0) and a1 and a2 and i6;
	s2 <= a0 and not(a1) and a2 and i5;
	s3 <= not(a0) and not(a1) and a2 and i4;
	s4 <= a0 and a1 and not(a2) and i3;
	s5 <= not(a0) and a1 and not(a2) and i2;
	s6 <= a0 and not(a1) and not(a2) and i1;
	s7 <= not(a0) and not(a1) and not(a2) and i0;
	
end arq;