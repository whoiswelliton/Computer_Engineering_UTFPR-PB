library ieee;
use ieee.std_logic_1164.all;

entity mux2x1 is
	port( seletor: in std_logic;
			entrada1: in integer range 0 to 15;
			entrada2: in integer range 0 to 15;
			saida: out integer range 0 to 15 );
end mux2x1;

architecture Behavioral of mux2x1 is
	
	begin
		saida <= entrada2 when seletor='1' else entrada1;
end Behavioral;