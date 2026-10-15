using System;
using System.Globalization;

class Rectangle
{
    private double width;
    private double height;

    public Rectangle()
    {
        width = 0;
        height = 0;
    }

    private static double ReadDouble(string prompt)
    {
        while (true)
        {
            Console.Write(prompt);
            string s = Console.ReadLine();
            if (s != null)
            {
                s = s.Trim().Replace(',', '.');
                if (double.TryParse(s, NumberStyles.Float, CultureInfo.InvariantCulture, out double v))
                    return v;
            }
            Console.WriteLine("  Невірне число, спробуйте ще раз.");
        }
    }

    public void Input()
    {
        width = ReadDouble("  Ширина: ");
        height = ReadDouble("  Висота: ");
    }

    public double Area()
    {
        return width * height;
    }

    public void Print()
    {
        Console.WriteLine("Ширина = " + width + ", висота = " + height + ", площа = " + Area());
    }
}

class Program
{
    static void Main()
    {
        const int N = 5;
        Rectangle[] rects = new Rectangle[N];

        for (int i = 0; i < N; i++)
        {
            rects[i] = new Rectangle();
            Console.WriteLine("Прямокутник " + (i + 1) + ":");
            rects[i].Input();
        }

        int maxIdx = 0;
        for (int i = 1; i < N; i++)
        {
            if (rects[i].Area() > rects[maxIdx].Area())
                maxIdx = i;
        }

        Console.WriteLine("\nНайбільша площа у прямокутника " + (maxIdx + 1) + ":");
        rects[maxIdx].Print();
    }
}
