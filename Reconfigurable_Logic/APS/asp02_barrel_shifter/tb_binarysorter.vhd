LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY tb_binarysorter IS
END tb_binarysorter;
 
ARCHITECTURE behavior OF tb_binarysorter IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT bshifter
    PORT(
         entrada : IN  std_logic_vector(3 downto 0);
         shift : IN  std_logic;
         num_shift : IN  std_logic_vector(1 downto 0);
         saida : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal entrada : std_logic_vector(3 downto 0) := (others => '0');
   signal shift : std_logic := '0';
   signal num_shift : std_logic_vector(1 downto 0) := (others => '0');

 	--Outputs
   signal saida : std_logic_vector(3 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   constant <clock>_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: bshifter PORT MAP (
          entrada => entrada,
          shift => shift,
          num_shift => num_shift,
          saida => saida
        );

   -- Clock process definitions
   <clock>_process :process
   begin
		<clock> <= '0';
		wait for <clock>_period/2;
		<clock> <= '1';
		wait for <clock>_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for <clock>_period*10;

      -- insert stimulus here 

      wait;
   end process;

END;
