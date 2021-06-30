library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

entity binarysorter is
	generic(N: integer := 4);
	PORT (input: IN STD_LOGIC_VECTOR((N-1) DOWNTO 0);
			aux: IN STD_LOGIC_VECTOR((N-1) DOWNTO 0);
			output: OUT STD_LOGIC_VECTOR(2**N-1 DOWNTO 0));
end binarysorter;

architecture ARQ of binarysorter is
	--signal aux: STD_LOGIC_VECTOR((N-1) DOWNTO 0);
begin
  
	gen1: for i in 0 to aux'range generate
	   aux(i) <= input AND (1 SRL i);
	end generate gen1;
	
	gen2: for i in output'range generate
		output(i) <= '1' when aux(i) = '1' else
					 '0' when aux(i) /='1';
	end generate gen2;

end ARQ;

