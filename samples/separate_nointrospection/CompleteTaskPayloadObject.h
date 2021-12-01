// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

// WARNING! Do not edit this file manually, your changes will be overwritten.

#pragma once

#ifndef COMPLETETASKPAYLOADOBJECT_H
#define COMPLETETASKPAYLOADOBJECT_H

#include "TodaySchema.h"

namespace graphql::today::object {
namespace stub::CompleteTaskPayloadStubs {

template <class TImpl>
concept HasTask = requires (TImpl impl, service::FieldParams params) 
{
	{ service::FieldResult<std::shared_ptr<Task>> { impl.getTask(std::move(params)) } };
};

template <class TImpl>
concept HasClientMutationId = requires (TImpl impl, service::FieldParams params) 
{
	{ service::FieldResult<std::optional<response::StringType>> { impl.getClientMutationId(std::move(params)) } };
};

template <class TImpl>
concept HasBeginSelectionSet = requires (TImpl impl, const service::SelectionSetParams params) 
{
	{ impl.beginSelectionSet(params) };
};

template <class TImpl>
concept HasEndSelectionSet = requires (TImpl impl, const service::SelectionSetParams params) 
{
	{ impl.endSelectionSet(params) };
};

} // namespace stub::CompleteTaskPayloadStubs

class CompleteTaskPayload
	: public service::Object
{
private:
	service::AwaitableResolver resolveTask(service::ResolverParams&& params);
	service::AwaitableResolver resolveClientMutationId(service::ResolverParams&& params);

	service::AwaitableResolver resolve_typename(service::ResolverParams&& params);

	struct Concept
	{
		virtual ~Concept() = default;

		virtual void beginSelectionSet(const service::SelectionSetParams& params) const = 0;
		virtual void endSelectionSet(const service::SelectionSetParams& params) const = 0;

		virtual service::FieldResult<std::shared_ptr<Task>> getTask(service::FieldParams&& params) const = 0;
		virtual service::FieldResult<std::optional<response::StringType>> getClientMutationId(service::FieldParams&& params) const = 0;
	};

	template <class T>
	struct Model
		: Concept
	{
		Model(std::shared_ptr<T>&& pimpl) noexcept
			: _pimpl { std::move(pimpl) }
		{
		}

		void beginSelectionSet(const service::SelectionSetParams& params) const final
		{
			if constexpr (stub::CompleteTaskPayloadStubs::HasBeginSelectionSet<T>)
			{
				_pimpl->beginSelectionSet(params);
			}
		}

		void endSelectionSet(const service::SelectionSetParams& params) const final
		{
			if constexpr (stub::CompleteTaskPayloadStubs::HasEndSelectionSet<T>)
			{
				_pimpl->endSelectionSet(params);
			}
		}

		service::FieldResult<std::shared_ptr<Task>> getTask(service::FieldParams&& params) const final
		{
			if constexpr (stub::CompleteTaskPayloadStubs::HasTask<T>)
			{
				return { _pimpl->getTask(std::move(params)) };
			}
			else
			{
				throw std::runtime_error(R"ex(CompleteTaskPayload::getTask is not implemented)ex");
			}
		}

		service::FieldResult<std::optional<response::StringType>> getClientMutationId(service::FieldParams&& params) const final
		{
			if constexpr (stub::CompleteTaskPayloadStubs::HasClientMutationId<T>)
			{
				return { _pimpl->getClientMutationId(std::move(params)) };
			}
			else
			{
				throw std::runtime_error(R"ex(CompleteTaskPayload::getClientMutationId is not implemented)ex");
			}
		}

	private:
		const std::shared_ptr<T> _pimpl;
	};

	CompleteTaskPayload(std::unique_ptr<Concept>&& pimpl);

	void beginSelectionSet(const service::SelectionSetParams& params) const final;
	void endSelectionSet(const service::SelectionSetParams& params) const final;

	const std::unique_ptr<Concept> _pimpl;

public:
	template <class T>
	CompleteTaskPayload(std::shared_ptr<T> pimpl)
		: CompleteTaskPayload { std::unique_ptr<Concept> { std::make_unique<Model<T>>(std::move(pimpl)) } }
	{
	}
};

} // namespace graphql::today::object

#endif // COMPLETETASKPAYLOADOBJECT_H
