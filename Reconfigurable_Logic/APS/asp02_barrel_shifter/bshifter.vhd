library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity binarysorter is
port (entrada: in bit_vector(3 downto 0);
		shift: in std_logic;
		num_shift: in std_logic_vector(1 downto 0);
		saida: out BIT_VECTOR(3 downto 0));
end binarysorter;

architecture arq of bshifter is
	signal i_num_shift: integer;
begin

	
	i_num_shift <= to_integer(unsigned(num_shift));
	saida <= entrada SLL i_num_shift when shift = '1' else
	         entrada SRL i_num_shift;

end arq;
