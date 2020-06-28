object supertest
{
	def loop(n: int): int
	{
		var ans = 0
		var i:int = 0
		while(i<n)
		{
			var j:int = i
			i = i + 1
			while(j<n)
			{
				j = j + 1
				ans = ans + j
			}
		}
		return ans
	}

	def _if(a: int)
	{
		if(a<10)
		{
			print(15)
		}
		else
		{
			if(a>20)
				print(20)
		}
	}

	def main()
	{
		var sum
		sum = loop(10)
		println(sum)

		_if(20)
	}
}
