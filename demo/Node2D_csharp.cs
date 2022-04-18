using Godot;
using System;

public class Node2D_csharp : Node2D
{
    // Declare member variables here. Examples:
    // private int a = 2;
    // private string b = "text";
    private Color[] colors = new Color[9];


    // Called when the node enters the scene tree for the first time.
    public override void _Ready()
    {
        colors[0] = Color.Color8(0, 0, 0);
        colors[1] = Color.Color8(255, 0, 255);
		colors[2] = Color.Color8(0, 0, 255);
		colors[3] = Color.Color8(0, 255, 0);
		colors[4] = Color.Color8(0, 128, 255);
		colors[5] = Color.Color8(255, 0, 0);
		colors[6] = Color.Color8(255, 128, 0);
		colors[7] = Color.Color8(255, 255, 0);
		colors[8] = Color.Color8(255, 255, 255);
    }

    public override void _Draw()
    {
		ulong startmsecs = OS.GetSystemTimeMsecs();

		// from http ://www.quitebasic.com/prj/math/mandelbrot/
		Color c;
		float l = 100.0f;
		for(int i=0; i<500;i++)
        {
			for(int j=0;j<500;j++)
            {
				float u = i / 250.0f - 1.5f;
				float v = j / 250.0f - 1.0f;
				float x = u;
				float y = v;
				float n = 0.0f;
				float r = x * x;
				float q = y * y;
				while((r+q)<4.0f && n<l)
                {
					y = 2.0f * x * y + v;
					x = r - q + u;
					r = x * x;
					q = y * y;
					n = n + 1.0f;
				}
				if (n < 10.0f)
				{
					c = colors[0];
				}
				else
				{
					c = colors[(int)(Mathf.Round(8.0f * (n - 10.0f) / (l - 10.0f)))];
				}
				DrawRect(new Rect2(new Vector2(i + 500, j), new Vector2(1, 1)), c, true, 1.0f, false);
			}
        }

		ulong stopmsecs = OS.GetSystemTimeMsecs();
		GD.Print("C# result milliseconds: ");
		GD.Print(stopmsecs - startmsecs);
	}

}
