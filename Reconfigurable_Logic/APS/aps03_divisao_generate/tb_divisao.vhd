LIBRARY ieee;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;
--		g) Desenvolver, simular e implementar um circuito divisor de três bits com generate:
ENTITY tb_divisao IS
END tb_divisao;
 
ARCHITECTURE arq OF tb_divisao IS 
  signal ent1,ent2,sai1,sai2 : std_logic_vector(2 downto 0) := (others => '0');
  signal onehot : std_logic_vector (2**3-1 downto 0);

BEGIN
	uut: entity work.divisao PORT MAP(		
		ent1 =>ent1, ent2 => ent2, sai1 =>sai1, sai2 => sai2	,y =>onehot );

	process
		variable i,j: integer;
		begin		-- 1/1		teste geral
		for i in 0 to 7 loop
			for j in 0 to 7 loop
				ent1 <= std_logic_vector(to_signed(i,3));
				ent2 <= std_logic_vector(to_signed(j,3));
				wait for 10 ns;
			end loop;
		end loop;	
   end process;
END arq;
	