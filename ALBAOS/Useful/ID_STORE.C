#use "idblock_api.lib"
// Use the reserved size that is explicitly set for this controller in its
//  hardware-specific library.
#if (!ZWORLD_RESERVED_SIZE)
   #error "This board has no reserved calibration constants area in its User" \
          " block."
   #fatal "Check your hardware manual to see if User block calibration" \
          " constants are expected."
#endif

#define UB_ADDR (4096*GetIDBlockSize()-ZWORLD_RESERVED_SIZE)
#define UB_SIZE (ZWORLD_RESERVED_SIZE - 6)  // omit markers
#define UB_INTS (UB_SIZE / sizeof(int))
#define UB_LAST (UB_INTS - 1)
#define VALUES_PER_LINE 10                  // not too narrow, not too wide

// Constants data array to write to User block (when enabled)
//------------------------------------------------------------------------------
#define UB_WRITE

char ub_array[UB_SIZE / 2] =
{
"ELEM01R42S009",
};


main()
{
	int i, n;

   #ifdef UB_WRITE
   if (writeUserBlock(UB_ADDR, ub_array, strlen(ub_array)+1))     //+1 add a null character
   {
      printf("cannot write User block\n");
   }
   else  // continue with read and report
   #endif
   if (readUserBlock(ub_array, UB_ADDR, 100))
   {
      printf("cannot read User block\n");
   }
   else
   {
   	printf("%s",ub_array);
   }
}

