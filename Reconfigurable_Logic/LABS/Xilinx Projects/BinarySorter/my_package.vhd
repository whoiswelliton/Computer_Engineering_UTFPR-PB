library IEEE;
use IEEE.STD_LOGIC_1164.all;

package my_package is
	component 
		PORT (input: IN STD_LOGIC_VECTOR((N-1) DOWNTO 0);
			aux: IN STD_LOGIC_VECTOR((N-1) DOWNTO 0);
			output: OUT STD_LOGIC_VECTOR(2**N-1 DOWNTO 0));
	
	end component
end my_package;

package body my_package is

end my_package;
