class BalloonJuiceSearch
{
	constructor(a, b, c)
	{
		this.root = new Balloon(a, b, c);
		this.balloons = [this.root];
		this.path = [];
	}

	linkBalloon(a, b, c, src) //confirms if a balloon is valid or not
	{
		if (a < 0 || b < 0 || c < 0)
			return;

		if (a == src.a && b == src.b && c == src.c)
			return;

		if (a > Balloon.AMAX  || b > Balloon.BMAX || c > Balloon.CMAX)
			return;

		var balloon = this.balloons.find(function(element){
			return a == element.a && b == element.b && c == element.c;
		});
		if (balloon == null)
		{
			balloon = new Balloon(a, b, c);
			balloon.depth = src.depth + 1;
			this.balloons.push(balloon);
		}

		if (!src.targets.some(function(element){ return a == element.a && b == element.b && c == element.c}))
		{
			src.targets.push(balloon);
		}
	}

	linkAllBalloonsFrom(src) //finds all valid balloons
	{
		var X, Y;

		//X = 0
		X = 0;

		Y = src.a + src.b - X;
		this.linkBalloon(X, Y, src.c, src); //A -> B
		this.linkBalloon(Y, X, src.c, src); //B -> A

		Y = src.b + src.c - X;
		this.linkBalloon(src.a, X, Y, src) //B -> C
		this.linkBalloon(src.a, Y, X, src) //C -> B

		Y = src.a + src.c - X;
		this.linkBalloon(X, src.b, Y, src); //A -> C
		this.linkBalloon(Y, src.b, X, src); //C -> A


		//Y = YMAX
		Y = Balloon.BMAX;
		X = src.c + src.b - Y;
		this.linkBalloon(src.a, Y, X, src); //C -> B
		X = src.a + src.b - Y;
		this.linkBalloon(X, Y, src.c, src); //A -> B

		Y = Balloon.CMAX;
		X = src.a + src.c - Y;
		this.linkBalloon(X, src.b, Y, src); //A -> C
		X = src.b + src.c - Y;
		this.linkBalloon(src.a, X, Y, src); //B -> C

		Y = Balloon.AMAX;
		X = src.b + src.a - Y;
		this.linkBalloon(Y, X, src.c, src); //B -> A
		X = src.c + src.a - Y;
		this.linkBalloon(Y, src.b, X, src); //C -> A

		return src.targets;
	}

	searchBalloon(a, b, c) //this is where we start
	{
		this.root.opened = true;

		var queue = [];
		var path = [];
		queue.push(this.root);
		// console.log(queue);


		while (queue.length > 0)
		{

			var current = queue.shift();

			//If the balloon jucie is found -- backtracking
			if (current.a == a && current.b == b && current.c == c)
			{
				var goal = current;

				while (goal != null)
				{
					this.path.unshift(goal);
					console.log(path);
					goal = goal.source;
					// console.log(goal);
				}

				console.log("Found: " + current + " At Depth " + current.depth);
				return current;
			}

			var targets = this.linkAllBalloonsFrom(current); //finds all available balloons
			for (var i = 0; i < targets.length; i++)
			{
				var child = targets[i];
				if (!child.opened)
				{
					child.opened = true;
					child.source = current;
					queue.push(child);
				}
			}
		}
		return null;
	}

	balloonsAtDepth(depth)
	{
		var balloons = this.balloons.filter(function(element)
		{
			return element.depth === depth;
		});
		return balloons;
	}
}
