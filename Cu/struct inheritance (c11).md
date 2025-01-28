Наследование структур.
```c
typedef struct point
{
	double x, y;
} point;

typedef struct
{
	struct point;
	double z;
} threepoint;

double threelength (threepoint p)
{
	return sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
}
```