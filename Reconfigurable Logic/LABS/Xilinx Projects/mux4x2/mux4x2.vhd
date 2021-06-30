library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity mux4x2 is
port(a, b, c, d, e: in std_logic;
					 x: out std_logic);
end mux4x2;

architecture arq of mux4x2 is
signal ti1, ti2, ti3: std_logic;
begin

ti1 <= a or b;
ti2 <= ti1 and c;
ti3 <= not(ti2) or d;
x <= ti3 and e;

end arq;

