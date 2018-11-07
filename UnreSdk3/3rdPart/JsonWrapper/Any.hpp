
#ifndef __ESONG_ANY_H_INC__
#define __ESONG_ANY_H_INC__


#include <string>
#include <cassert>
#include <typeinfo>

namespace ESong
{
	class Any
	{
	public:
		Any() : content(0)
		{
		}

		Any(const char* value) : content(new holder<std::string>(value))
		{
		}

		template<typename ValueType>
		Any(const ValueType& value) : content(new holder<ValueType>(value))
		{
		}

		Any(const Any& other) : content(other.content ? other.content->clone() : 0)
		{
		}

		~Any()
		{
			delete content;
		}

	public:

		Any& swap(Any& rhs)
		{
			std::swap(content, rhs.content);
			return *this;
		}

		template<typename ValueType>
		Any& operator=(const ValueType& rhs)
		{
			Any(rhs).swap(*this);
			return *this;
		}

		Any& operator=(Any rhs)
		{
			Any(rhs).swap(*this);
			return *this;
		}

	public:

		bool empty() const
		{
			return !content;
		}

		void clear()
		{
			Any().swap(*this);
		}

		const std::type_info & type() const
		{
			return content ? content->type() : typeid(void);
		}

	private:

		class placeholder
		{
		public:
			virtual ~placeholder()
			{
			}

		public:
			virtual const std::type_info &type() const = 0;

			virtual placeholder * clone() const = 0;

		};

		template<typename ValueType>
		class holder: public placeholder
		{
		public:
			holder(const ValueType& value) : held(value)
			{
			}

		public:

			virtual const std::type_info & type() const
			{
				return typeid(ValueType);
			}

			virtual placeholder * clone() const
			{
				return new holder(held);
			}

		public:
			ValueType held;

		private:
			holder & operator=(const holder&);
		};


	private:

		template<typename ValueType>
		friend ValueType * AnyCast(Any *);

		template<typename ValueType>
		friend ValueType AnyCast(Any & operand);

	private:
		placeholder *content;
	};


	inline void swap(Any & lhs, Any & rhs)
	{
		lhs.swap(rhs);
	}

	template<typename ValueType>
	ValueType *AnyCast(Any* operand)
	{
		return operand && operand->type() == typeid(ValueType) ? &static_cast<Any::holder<ValueType> *>(operand->content)->held : 0;
	}

	template<typename ValueType>
	inline const ValueType *AnyCast(const Any* operand)
	{
		return AnyCast<ValueType>(const_cast<Any *>(operand));
	}

	template<typename ValueType>
	ValueType AnyCast(Any & operand)
	{
		if(operand.type() != typeid(ValueType))
			throw "Type Error";

		return static_cast<Any::holder<ValueType> *>(operand.content)->held;
	}

	template<typename ValueType>
	inline ValueType AnyCast(const Any & operand)
	{
		return AnyCast<const Any &>(const_cast<Any &>(operand));
	}
}

#endif