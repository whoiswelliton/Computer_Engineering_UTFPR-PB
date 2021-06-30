library ieee;
use ieee.std_logic_1164.all;

entity dem2x4 is
	port( aux3 : in std_logic_vector(1 downto 0);
			aux4 : out std_logic_vector(3 downto 0));
end dem2x4;

architecture Behavioral of dem2x4 is

	begin
		aux4 <=	"0001" when aux3 = "00" else
					"0010" when aux3 = "01" else
					"0100" when aux3 = "10" else
					"1000" when aux3 = "11";
end Behavioral;