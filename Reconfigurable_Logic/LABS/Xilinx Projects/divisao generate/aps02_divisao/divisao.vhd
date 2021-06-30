library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.ALL;
	--		g) Desenvolver, simular e implementar um circuito divisor de três bits: 
entity divisao is
	GENERIC (N : integer := 3);
	port(	ent1, ent2 : IN std_logic_vector (N-1 downto 0);
			sai1, sai2 : OUT std_logic_vector (N-1 downto 0));
end divisao;

architecture ent of divisao is
	signal a, b : integer;
begin

	-- to_unsigned(int, numbits), Esta função transforma um inteiro em um vetor
	a <= to_integer(unsigned(ent1));		--a / b
	b <= to_integer(unsigned(ent2));
	
	sai1 <= "111" WHEN b=0 ELSE
			  "001" WHEN a=b ELSE
			  "000" WHEN a<b ELSE
			  std_logic_vector(to_unsigned(a,3)) WHEN b=1 ELSE
			  std_logic_vector(to_unsigned(1,3)) WHEN (a=(1*b) OR a=(1+b)) ELSE
			  std_logic_vector(to_unsigned(2,3)) WHEN (a=(2*b) OR a=(1+2*b) OR a=(2+2*b)) ELSE
			  std_logic_vector(to_unsigned(3,3)) WHEN (a=(3*b) OR a=(1+3*b) OR a=(2+3*b) OR a=(3+3*b)) 
			  ELSE "000";
	sai2 <= "111" WHEN b<=0 ELSE
			  "000" WHEN b=1 ELSE
			  std_logic_vector(to_unsigned(a,3)) WHEN a<b ELSE
			  std_logic_vector(to_unsigned(0,3)) WHEN a=b*b ELSE
			  std_logic_vector(to_unsigned(1,3)) WHEN a=b+1 OR a=2*b+1 OR a=3*b+1 ELSE
			  std_logic_vector(to_unsigned(2,3)) WHEN a=b+2 OR a=2*b+1 OR a=3*b+1 ELSE
			  std_logic_vector(to_unsigned(3,3)) WHEN a=b+3 OR a=2*b+1 OR a=3*b+1
			  ELSE "000";
end ent;

