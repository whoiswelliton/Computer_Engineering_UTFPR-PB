library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity clkgen4 is
	port( mclk, reset: in std_logic;
			clk: out std_logic );
end clkgen4;

architecture Behavioral of clkgen4 is

	constant C: integer := 2*50_000_000;
	constant N: integer := 255;
	
	begin

		process(mclk, reset)
		
			variable i: integer range 1 to C := 1;
			variable v_clk: std_logic := '0';
			
			begin
				if (reset = '1') then 
					i := 1; 
					v_clk := '0';
				elsif(mclk'event and mclk='1') then 
					i := i + 1;
				if (i = C/N) then 
					i := 1; 
					v_clk := not(v_clk);
				end if;
				clk <= v_clk; 
				end if;
			end process;
end Behavioral;