library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.ALL;
	--		g) Desenvolver, simular e implementar um circuito divisor de três bits: 
entity divisao is
	GENERIC (N : integer := 3);
	port(	ent1, ent2 : IN std_logic_vector (N-1 downto 0);
			sai1, sai2 : OUT std_logic_vector (N-1 downto 0);
			y : INOUT std_logic_vector (2**N-1 downto 0)			
			);
end divisao;

architecture ent of divisao is

	signal a,b,inteiro: integer range 0 to 2**N-1 := 0;
	TYPE array_integer IS ARRAY (2**N-1 DOWNTO 0) of integer range 0 to 2**N-1 ;
	SIGNAL vetor_subtracao : array_integer ;
begin

	gen: FOR i IN vetor_subtracao'range GENERATE
	
		vetor_subtracao(i) <= to_integer(unsigned(ent1)) - i * to_integer(unsigned(ent2)); --vetor de multiplas subtracoes
		y(i) <= '1' WHEN vetor_subtracao(i) >=0  AND ( vetor_subtracao(i)-to_integer(unsigned(ent2)) < 0 ) --posicao onehot da divisao inteira
						ELSE '0';
		
	END GENERATE gen;	
	
	--onehot-----------------------------------
			 inteiro <= 0 WHEN "00000001" = y ELSE
							1 WHEN "00000010" = y ELSE
							2 WHEN "00000100" = y ELSE
							3 WHEN "00001000" = y ELSE
							4 WHEN "00010000" = y ELSE
							5 WHEN "00100000" = y ELSE
							6 WHEN "01000000" = y ELSE
							7 WHEN "10000000" = y ELSE
							0;			
	-------------------------------------------
	a <= to_integer(unsigned(ent1));
	b <= to_integer(unsigned(ent2));
		
	sai1 <= std_logic_vector(to_unsigned( inteiro, N )) WHEN (a /=0 AND b/=0) ELSE "111" WHEN b=0 ELSE "000"; 
	sai2 <= std_logic_vector(to_unsigned( a-inteiro*b, N)) WHEN b /=0 ELSE "111";  
	
end ent;
