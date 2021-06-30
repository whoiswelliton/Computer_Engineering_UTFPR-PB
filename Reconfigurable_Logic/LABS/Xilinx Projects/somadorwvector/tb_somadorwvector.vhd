library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all

entity tb_somadorwvector is
end tb_somadorwvector;

architecture xuxa of tb_somadorwvector is
	signal ta, tb: std_logic_vector(1 down to 0);
	signal ts: std_logic_vector(2 down to 0);
begin
	uut: entity work.somadorwvector(xuxa);
	port map (ta,tb, ts);
	
	process
	variable i, j: integer;
	begin
	for i in 0 to 3 loop
			for j in 0 to 3 loop
			ta <= std_logic_vector(to_unsigned(i,2));
			tb <= std_logic_vector(to_unsigned(j,2));
			wait for 10 ns;
			
			end loop;
		end loop;
	end process
end xuxa;

