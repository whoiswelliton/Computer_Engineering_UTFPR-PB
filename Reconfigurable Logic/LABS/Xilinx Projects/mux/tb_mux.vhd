library ieee;
use ieee.std_logic_1164.all;

entity tb_mux is
end tb_mux;

architecture arq of tb_mux is
	signal ts0, ts1, ts2, ts3, ts4, ts5, ts6, ts7, ta0, ta1, ta2, ty: std_logic;
	
	begin
		uut: entity work.mux(arq)
		port map (i7 => ts7,
					 i6 => ts6,
					 i5 => ts5,
					 i4 => ts4,
					 i3 => ts3,
					 i2 => ts2,
					 i1 => ts1,
					 i0 => ts0,
					 a2 => ta2,
					 a1 => ta1,
					 a0 => ta0,
					 y => ty);
process begin

	ts7 <= '0'; ts6 <= '0';ts5 <= '0';ts4 <= '0';ts3 <= '0';ts2 <= '0';ts1 <= '0';ts0 <= '1';
	ta2 <= '0';ta1 <= '0';ta0 <= '0';
	wait for 10 ns;
	
	ts7 <= '0'; ts6 <= '0';ts5 <= '0';ts4 <= '0';ts3 <= '0';ts2 <= '0';ts1 <= '0';ts0 <= '0';
	ta2 <= '0';ta1 <= '0';ta0 <= '0';
	wait for 10 ns;
end process;
end arq;
