library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity comparador2bits is
port(a0, a1, b0, b1: in std_logic;
					  x:  out std_logic);
end comparador2bits;

architecture arq of comparador2bits is
signal ti1, ti2: std_logic;
begin

ti1 <= a0 xor b0;
ti2 <= a1 xor b1;

x <= not(ti1) and not(ti2);

end arq;

