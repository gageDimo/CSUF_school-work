class Balloon
{
	constructor(a, b, c)
	{
		Balloon.AMAX = 19;
		Balloon.BMAX = 13;
		Balloon.CMAX = 7;

		this.a = a;
		this.b = b;
		this.c = c;

		this.targets = [];
		this.source = null;
		this.opened = false;
		this.depth = 0;
	}

	toString()
	{
		return "(" + this.a + "," + this.b + "," + this.c + ")";
	}

}
