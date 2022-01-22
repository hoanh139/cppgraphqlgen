// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

// WARNING! Do not edit this file manually, your changes will be overwritten.

#pragma once

#ifndef MESSAGEOBJECT_H
#define MESSAGEOBJECT_H

#include "ValidationSchema.h"

namespace graphql::validation::object {
namespace methods::MessageHas {

template <class TImpl>
concept getBodyWithParams = requires (TImpl impl, service::FieldParams params)
{
	{ service::AwaitableScalar<std::optional<std::string>> { impl.getBody(std::move(params)) } };
};

template <class TImpl>
concept getBody = requires (TImpl impl)
{
	{ service::AwaitableScalar<std::optional<std::string>> { impl.getBody() } };
};

template <class TImpl>
concept getSenderWithParams = requires (TImpl impl, service::FieldParams params)
{
	{ service::AwaitableScalar<response::IdType> { impl.getSender(std::move(params)) } };
};

template <class TImpl>
concept getSender = requires (TImpl impl)
{
	{ service::AwaitableScalar<response::IdType> { impl.getSender() } };
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

} // namespace methods::MessageHas

class Message final
	: public service::Object
{
private:
	service::AwaitableResolver resolveBody(service::ResolverParams&& params) const;
	service::AwaitableResolver resolveSender(service::ResolverParams&& params) const;

	service::AwaitableResolver resolve_typename(service::ResolverParams&& params) const;

	struct Concept
	{
		virtual ~Concept() = default;

		virtual void beginSelectionSet(const service::SelectionSetParams& params) const = 0;
		virtual void endSelectionSet(const service::SelectionSetParams& params) const = 0;

		virtual service::AwaitableScalar<std::optional<std::string>> getBody(service::FieldParams&& params) const = 0;
		virtual service::AwaitableScalar<response::IdType> getSender(service::FieldParams&& params) const = 0;
	};

	template <class T>
	struct Model
		: Concept
	{
		Model(std::shared_ptr<T>&& pimpl) noexcept
			: _pimpl { std::move(pimpl) }
		{
		}

		service::AwaitableScalar<std::optional<std::string>> getBody(service::FieldParams&& params) const final
		{
			if constexpr (methods::MessageHas::getBodyWithParams<T>)
			{
				return { _pimpl->getBody(std::move(params)) };
			}
			else if constexpr (methods::MessageHas::getBody<T>)
			{
				return { _pimpl->getBody() };
			}
			else
			{
				throw std::runtime_error(R"ex(Message::getBody is not implemented)ex");
			}
		}

		service::AwaitableScalar<response::IdType> getSender(service::FieldParams&& params) const final
		{
			if constexpr (methods::MessageHas::getSenderWithParams<T>)
			{
				return { _pimpl->getSender(std::move(params)) };
			}
			else if constexpr (methods::MessageHas::getSender<T>)
			{
				return { _pimpl->getSender() };
			}
			else
			{
				throw std::runtime_error(R"ex(Message::getSender is not implemented)ex");
			}
		}

		void beginSelectionSet(const service::SelectionSetParams& params) const final
		{
			if constexpr (methods::MessageHas::beginSelectionSet<T>)
			{
				_pimpl->beginSelectionSet(params);
			}
		}

		void endSelectionSet(const service::SelectionSetParams& params) const final
		{
			if constexpr (methods::MessageHas::endSelectionSet<T>)
			{
				_pimpl->endSelectionSet(params);
			}
		}

	private:
		const std::shared_ptr<T> _pimpl;
	};

	Message(std::unique_ptr<const Concept>&& pimpl) noexcept;

	service::TypeNames getTypeNames() const noexcept;
	service::ResolverMap getResolvers() const noexcept;

	void beginSelectionSet(const service::SelectionSetParams& params) const final;
	void endSelectionSet(const service::SelectionSetParams& params) const final;

	const std::unique_ptr<const Concept> _pimpl;

public:
	template <class T>
	Message(std::shared_ptr<T> pimpl) noexcept
		: Message { std::unique_ptr<const Concept> { std::make_unique<Model<T>>(std::move(pimpl)) } }
	{
	}
};

} // namespace graphql::validation::object

#endif // MESSAGEOBJECT_H
