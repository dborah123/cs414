/*
 * page-faults.d
 */

fbt::vm_fault_trap:entry
/pid == $target/
{
    printf("PAGE FAULT: Address at fault: %p", arg1);
}

fbt::vm_fault_trap:return
/pid == $target && arg1 == 0/
{
	printf("Page fault handled successfully");
}

fbt::vm_fault_trap:return
/pid == $target && arg1 != 0/
{
    printf("Page fault was not handled successfully");
}

BEGIN {
	printf("Program Start");
}

END {
	printf("Program End");
}
