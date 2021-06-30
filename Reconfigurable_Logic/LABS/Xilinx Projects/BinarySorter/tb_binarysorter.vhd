LIBRARY ieee;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;
--		g) Desenvolver, simular e implementar um circuito divisor de três bits com generate:
ENTITY tb_divisao IS
	generic(N: integer := 4);
END tb_divisao;
 
ARCHITECTURE arq OF tb_divisao IS 
  signal ent : std_logic_vector((N-1) DOWNTO 0);
  signal saida : std_logic_vector (2**N-1 downto 0);
  
BEGIN
	uut: entity work.binarysorter PORT MAP(		
		input =>ent, output => saida );

	process
		variable j: integer;
		begin		-- 1/1		teste geral
			for j in 0 to 7 loop
				ent <= std_logic_vector(to_signed(j,N));
				wait for 10 ns;
		end loop;	
   end process;
END arq;
	