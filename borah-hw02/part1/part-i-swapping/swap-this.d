/*
 * page-faults.d
 */

fbt::vm_fault_trap:entry
/pid == $target/
{
    self->ts = timestamp;
}

fbt::vm_fault_trap:return
/pid == $target /
{
    @ = quantize(timestamp - self->ts);
    self->ts = 0;
}

BEGIN {
	printf("Program Start");
}

END {
	printf("Program End");
}
