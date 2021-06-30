rotulo: FOR <de parametro> IN <ate parametro> GENERATE
codigo concorrente
END GENERATE <rotulo>;

--------------------------------------
exemplo
ENTITY address_decoder IS
	PORT (x: IN BIT_VECTOR(2 DOWNTO 0);
		  y: OUT BIT_VECTOR(7 DOWNTO 0));
END address_decoder;

ARCHITECTURE arq OF address_decoder is
BEGIN

	y <= "00000001" WHEN x = "000" ELSE
		 "00000010" WHEN x = "001" ELSE
		 "00000100" WHEN x = "010" ELSE
		 "00001000" WHEN x = "011" ELSE
		 "00010000" WHEN x = "100" ELSE
		 "00100000" WHEN x = "101" ELSE
		 "01000000" WHEN x = "110" ELSE
		 "10000000";
END arq;
---------------------------------------

ENTITY address_decoder IS
	GENERIC (N: INTEGER := 3 );
	PORT (x: IN INTEGER RANGE(0 TO 2**N-1);
		  y: OUT BIT_VECTOR(2**N-1 DOWNTO 0));
END address_decoder;

ARCHITECTURE arq OF address_decoder is
BEGIN

	gen: FOR i IN x'range GENERATE
		y(i) <= '1' WHEN i=x ELSE '0';
	END GENERATE gen;
END arq;



--	architecture arq of bshifter is
--		signal vetor : std_logic_vector(9 downto 0);
--	begin
--		vetor <= "000" & entrada & "000";
--		gen: FOR i IN 0 to 3 GENERATE
	
--			saida(i) <= vetor(3+i+to_integer(unsigned(num_shift)))  WHEN shift(0)='1' ELSE
--							vetor(3+i-to_integer(unsigned(num_shift)));
--		END GENERATE gen;
			
--	end arq;
