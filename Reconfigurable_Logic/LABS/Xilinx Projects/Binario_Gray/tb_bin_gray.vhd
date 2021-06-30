library ieee;
use ieee.std_logic_1164.all;

entity tb_bin_gray is
end tb_bin_gray;

architecture arq of tb_bin_gray is
	signal sg0, sg1, sg2, sg3, sb0, sb1, sb2, sb3: std_logic;
	
	begin
	uut: entity work.bin_gray (arq)
	
		port map (g3 => sg3,
					 g2 => sg2,
					 g1 => sg1,
					 g0 => sg0,
					 b0 => sb0,
					 b1 => sb1,
					 b2 => sb2,
					 b3 => sb3);
		process begin
		
		sb0 <= '0'; sb1 <= '0'; sb1 <= '0' ; sb3 <= '0';
		wait for 10 ns;
		sb0 <= '0'; sb1 <= '0'; sb1 <= '0' ; sb3 <= '1';
		wait for 10 ns;
		sb0 <= '0'; sb1 <= '0'; sb1 <= '1' ; sb3 <= '0';
		wait for 10 ns;
		sb0 <= '0'; sb1 <= '0'; sb1 <= '1' ; sb3 <= '1';
		wait for 10 ns;
		sb0 <= '0'; sb1 <= '1'; sb1 <= '0' ; sb3 <= '0';
		wait for 10 ns;
		sb0 <= '0'; sb1 <= '1'; sb1 <= '0' ; sb3 <= '1';
		wait for 10 ns;
		sb0 <= '0'; sb1 <= '1'; sb1 <= '1' ; sb3 <= '0';
		wait for 10 ns;
		sb0 <= '0'; sb1 <= '1'; sb1 <= '1' ; sb3 <= '1';
		wait for 10 ns;
		sb0 <= '1'; sb1 <= '0'; sb1 <= '0' ; sb3 <= '0';
		wait for 10 ns;
		sb0 <= '1'; sb1 <= '0'; sb1 <= '0' ; sb3 <= '1';
		wait for 10 ns;
		sb0 <= '1'; sb1 <= '0'; sb1 <= '1' ; sb3 <= '0';
		wait for 10 ns;
		sb0 <= '1'; sb1 <= '0'; sb1 <= '1' ; sb3 <= '1';
		wait for 10 ns;
		sb0 <= '1'; sb1 <= '1'; sb1 <= '0' ; sb3 <= '0';
		wait for 10 ns;
		sb0 <= '1'; sb1 <= '1'; sb1 <= '0' ; sb3 <= '1';
		wait for 10 ns;
		sb0 <= '1'; sb1 <= '1'; sb1 <= '1' ; sb3 <= '0';
		wait for 10 ns;
		sb0 <= '1'; sb1 <= '1'; sb1 <= '1' ; sb3 <= '1';
		wait for 10 ns;
		
	end process;
	end arq;