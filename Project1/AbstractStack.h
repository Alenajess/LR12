template <typename T>
class AbstractStack
{
public:
	virtual void Push(const T) = 0;
	virtual void Pop(T&) = 0;
	virtual void Peek(T&) = 0;
	virtual int GetSize() const = 0;
};