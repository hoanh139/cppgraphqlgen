// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

// WARNING! Do not edit this file manually, your changes will be overwritten.

#pragma once

#ifndef NESTEDTYPEOBJECT_H
#define NESTEDTYPEOBJECT_H

#include "TodaySchema.h"

namespace graphql::today::object {
namespace methods::NestedTypeHas {

template <class TImpl>
concept getDepthWithParams = requires (TImpl impl, service::FieldParams params)
{
	{ service::AwaitableScalar<int> { impl.getDepth(std::move(params)) } };
};

template <class TImpl>
concept getDepth = requires (TImpl impl)
{
	{ service::AwaitableScalar<int> { impl.getDepth() } };
};

template <class TImpl>
concept getNestedWithParams = requires (TImpl impl, service::FieldParams params)
{
	{ service::AwaitableObject<std::shared_ptr<NestedType>> { impl.getNested(std::move(params)) } };
};

template <class TImpl>
concept getNested = requires (TImpl impl)
{
	{ service::AwaitableObject<std::shared_ptr<NestedType>> { impl.getNested() } };
};

template <class TImpl>
concept beginSelectionSet = requires (TImpl impl, const service::SelectionSetParams params)
{
	{ impl.beginSelectionSet(params) };
};

template <class TImpl>
concept endSelectionSet = requires (TImpl impl, const service::SelectionSetParams params)
{
	{ impl.endSelectionSet(params) };
};

} // namespace methods::NestedTypeHas

class NestedType
	: public service::Object
{
private:
	service::AwaitableResolver resolveDepth(service::ResolverParams&& params) const;
	service::AwaitableResolver resolveNested(service::ResolverParams&& params) const;

	service::AwaitableResolver resolve_typename(service::ResolverParams&& params) const;

	struct Concept
	{
		virtual ~Concept() = default;

		virtual void beginSelectionSet(const service::SelectionSetParams& params) const = 0;
		virtual void endSelectionSet(const service::SelectionSetParams& params) const = 0;

		virtual service::AwaitableScalar<int> getDepth(service::FieldParams&& params) const = 0;
		virtual service::AwaitableObject<std::shared_ptr<NestedType>> getNested(service::FieldParams&& params) const = 0;
	};

	template <class T>
	struct Model
		: Concept
	{
		Model(std::shared_ptr<T>&& pimpl) noexcept
			: _pimpl { std::move(pimpl) }
		{
		}

		service::AwaitableScalar<int> getDepth(service::FieldParams&& params) const final
		{
			if constexpr (methods::NestedTypeHas::getDepthWithParams<T>)
			{
				return { _pimpl->getDepth(std::move(params)) };
			}
			else if constexpr (methods::NestedTypeHas::getDepth<T>)
			{
				return { _pimpl->getDepth() };
			}
			else
			{
				throw std::runtime_error(R"ex(NestedType::getDepth is not implemented)ex");
			}
		}

		service::AwaitableObject<std::shared_ptr<NestedType>> getNested(service::FieldParams&& params) const final
		{
			if constexpr (methods::NestedTypeHas::getNestedWithParams<T>)
			{
				return { _pimpl->getNested(std::move(params)) };
			}
			else if constexpr (methods::NestedTypeHas::getNested<T>)
			{
				return { _pimpl->getNested() };
			}
			else
			{
				throw std::runtime_error(R"ex(NestedType::getNested is not implemented)ex");
			}
		}

		void beginSelectionSet(const service::SelectionSetParams& params) const final
		{
			if constexpr (methods::NestedTypeHas::beginSelectionSet<T>)
			{
				_pimpl->beginSelectionSet(params);
			}
		}

		void endSelectionSet(const service::SelectionSetParams& params) const final
		{
			if constexpr (methods::NestedTypeHas::endSelectionSet<T>)
			{
				_pimpl->endSelectionSet(params);
			}
		}

	private:
		const std::shared_ptr<T> _pimpl;
	};

	NestedType(std::unique_ptr<Concept>&& pimpl) noexcept;

	service::TypeNames getTypeNames() const noexcept;
	service::ResolverMap getResolvers() const noexcept;

	void beginSelectionSet(const service::SelectionSetParams& params) const final;
	void endSelectionSet(const service::SelectionSetParams& params) const final;

	const std::unique_ptr<Concept> _pimpl;

public:
	template <class T>
	NestedType(std::shared_ptr<T> pimpl) noexcept
		: NestedType { std::unique_ptr<Concept> { std::make_unique<Model<T>>(std::move(pimpl)) } }
	{
	}
};

} // namespace graphql::today::object

#endif // NESTEDTYPEOBJECT_H
