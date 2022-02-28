/*
 * mystrace.d
 */

syscall:::entry
/arg5 != 0 && arg4 !=0/
{
	printf("%s(%d, %d, %d, %d, %d, %d)\n", 
			probefunc, 
			arg0, 
			arg1, 
			arg2, 
			arg3, 
			arg4, 
			arg5
		);
}

syscall:::entry
/arg4 != 0 && arg5 == 0/
{
	printf("%s(%d, %d, %d, %d, %d)\n", 
			probefunc, 
			arg0, 
			arg1, 
			arg2, 
			arg3, 
			arg4
		);

}

syscall:::entry
/arg2 != 0 && arg3 == 0/
{
	printf("%s(%d, %d, %d)\n", probefunc, arg0, arg1, arg2);
}

syscall:::entry
/arg1 != 0 && arg3 == 0/
{
	printf("%s(%d, %d)\t", probefunc, arg0, arg1);
}

syscall:::entry
/arg3 != 0 && arg4 == 0/
{
	printf("%s(%d, %d, %d, %d)\n", 
			probefunc, 
			arg0, 
			arg1, 
			arg2, 
			arg3
		);

}


syscall:::entry
/arg0 != 0 && arg1 == 0/
{
	printf("%s(%d)\n", probefunc, arg0);
}
