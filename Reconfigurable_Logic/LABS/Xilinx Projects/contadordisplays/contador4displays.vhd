----- top -----------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use work.meu_pacote.all;

entity top is
	generic(freq : integer := 4;
			  valor: integer := 300);	
	port( mclk, reset: in std_logic;
			selout: out std_logic_vector(3 downto 0);
			saida: out std_logic_vector(6 downto 0));
end entity;

architecture arq of top is
	signal result, resultbcd: std_logic_vector(15 downto 0);
	signal sd: std_logic_vector(3 downto 0);
begin
	map_1: entity work.multidisp(arq)
		port map(mclk, sd, selout);
	map_2: entity work.contador(arq)
		generic map(freq, valor)
		port map(mclk, reset, result);
	resultbcd <= to_bcd(result);
	map_3: entity work.bcd_decod(arq)
		port map(resultbcd, sd, saida);
end arq;

---------- meu pacote ---------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;

package meu_pacote is
	component multidisp is
		port(mclk: in std_logic;
			  sd, selout: out std_logic_vector(3 downto 0));
	end component;
	
	component contador is
		generic(freq, valor: integer);
		port(mclk, reset: in std_logic;
				clk: out std_logic_vector(15 downto 0));
	end component;
	
	component bcd_decod is
	port(result: in std_logic_vector(15 downto 0);
		  selout: in std_logic_vector(3 downto 0);
		  saida: out std_logic_vector(6 downto 0));
	end component;
	 
	function to_bcd (bin : std_logic_vector(15 downto 0) ) return std_logic_vector;
end meu_pacote;

package body meu_pacote is
	function to_bcd ( bin : std_logic_vector(15 downto 0) ) return std_logic_vector is
	variable i : integer:=0;
	variable bcd : std_logic_vector(15 downto 0) := (others => '0');
	variable bint : std_logic_vector(15 downto 0) := bin;

	begin
	for i in 0 to 15 loop 
		bcd(15 downto 1) := bcd(14 downto 0); 
		bcd(0) := bint(15);
		bint(15 downto 1) := bint(14 downto 0);
		bint(0) :='0';

		if(i < 15 and bcd(3 downto 0) > "0100") then 
			bcd(3 downto 0) := bcd(3 downto 0) + "0011";
		end if;

		if(i < 15 and bcd(7 downto 4) > "0100") then 
			bcd(7 downto 4) := bcd(7 downto 4) + "0011";
		end if;

		if(i < 15 and bcd(11 downto 8) > "0100") then 
			bcd(11 downto 8) := bcd(11 downto 8) + "0011";
		end if;
	
		if(i < 15 and bcd(15 downto 12) > "0100") then 
			bcd(15 downto 12) := bcd(15 downto 12) + "0011";
		end if;
	end loop;
	return bcd;
end to_bcd;
end meu_pacote;

----------  multi disp ---------
library ieee; use ieee.std_logic_1164.all; use ieee.numeric_std.all;
entity multidisp is
	port(mclk: in std_logic; sd, clk: out std_logic_vector(3 downto 0));
end entity;
architecture arq of multidisp is
	constant N: integer := 50_000_000;
	--constant N: integer := 1600;
begin
	process(mclk)
	variable i: integer range 1 to N := 1;
	variable j: integer range 0 to 4 := 0;
	variable v_clk: std_logic_vector (3 downto 0) := "0000";
	begin
		if(mclk'event and mclk='1') then 
		i := i + 1;
			if (i = N/800) then 
				i := 1; 
				if(j = 0) then
					j := j + 1;
					v_clk := "1110";
				elsif(j = 1) then
					j := j+1;
					v_clk := "1101";
				elsif(j=2) then
					j :=j+1;
					v_clk := "1011";
				elsif(j=3) then
					j := 0;
					v_clk := "0111";
				end if;
			end if;
		clk <= v_clk;
		sd <= v_clk;
		end if;
	end process;
end arq;

-------------- contador ----------------
library ieee; use ieee.std_logic_1164.all; use ieee.numeric_std.all;
entity contador is
	generic(freq, valor : integer);
	port(mclk, reset: in std_logic; clk: out std_logic_vector(15 downto 0));
end entity;

architecture arq of contador is
	constant N: integer := 50_000_000;
	--constant N: integer := 8;
begin
	process(mclk, reset)
	variable i: integer range 1 to N := 1;
	variable v_clk: integer range 0 to 2**16-1 := 0;
	begin
		if (reset = '1') then 
			i := 1; 
			v_clk := 0;
		elsif(mclk'event and mclk='1') then 
			i := i + 1;
			if (i = N/(2*freq)) then 
				i := 1; 
				v_clk := v_clk + 1;
			end if;
			if (v_clk = valor) then
				v_clk := 0;
			end if;
		clk <= std_logic_vector(to_unsigned(v_clk, 16));	
		end if;
	end process;
end arq;

----------- bcd decod ----------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

entity bcd_decod is
	port( resultvec: IN std_logic_vector(15 downto 0);
			selout: in std_logic_vector(3 downto 0);
			segmentos: OUT std_logic_vector(6 DOWNTO 0));
end bcd_decod;

architecture arq of bcd_decod is
	signal result: integer range 0 to 15;
	signal val: std_logic_vector(3 downto 0);
begin
	val <= resultvec(15 downto 12) when selout = "0111" else
			 resultvec(11 downto 8) when selout = "1011" else
			 resultvec(7 downto 4) when selout = "1101" else
			 resultvec(3 downto 0);

	result <= to_integer(unsigned(val));	
segmentos <= "0000001" when result = 0 else -- '0'
				 "1001111" when result = 1 else -- '1'
				 "0010010" when result = 2 else -- '2'
				 "0000110" when result = 3 else -- '3'
				 "1001100" when result = 4 else -- '4'
				 "0100100" when result = 5 else -- '5'
				 "0100000" when result = 6 else -- '6'
				 "0001111" when result = 7 else -- '7'
				 "0000000" when result = 8 else -- '8'
				 "0000100" when result = 9 else -- '9'
				 "0001000" when result = 10 else -- 'A'
				 "1100000" when result = 11 else -- 'B'
				 "0110001" when result = 12 else -- 'C'
				 "1000010" when result = 13 else -- 'D'
				 "0110000" when result = 14 else -- 'E'
				 "0111000" when result = 15 else -- 'F'
				 "1111111";
end arq;

------------ net ------------------
net selout(3) loc=K14; #display4
net selout(2) loc=M13; #display3
net selout(1) loc=J12; #display2
net selout(0) loc=F12; #display1

net saida(6) loc=L14; #segA
net saida(5) loc=H12; #segB
net saida(4) loc=N14; #segC
net saida(3) loc=N11; #segD
net saida(2) loc=P12; #segE
net saida(1) loc=L13; #segF
net saida(0) loc=M12; #segG

net mclk loc=B8; #clk
net reset loc=G12; #reset