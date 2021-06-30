library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

entity somadorwvector is
port(a, b: in std_logic_vector(1 downto 0);
		  s: out std_logic_vector(2 downto 0));
end somadorwvector;

architecture xuxa of somadorwvector is
	signal sia, sib: integer range 0 to 3;
begin
	sia <= to_integer(unsigned(a));
	sib <= to_integer(unsigned(b));
	s <= std_logic_vector(to_unsigned(sia + sib, 3));
end xuxa;

