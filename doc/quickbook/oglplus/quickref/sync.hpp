/*
 *  Copyright 2014-2019 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

//[oglplus_sync

class Sync {
public:
    struct Property {
        using Condition = __SyncCondition;

        using Type = __SyncType;

        using Status = __SyncStatus;

        using WaitResult = __SyncWaitResult;
    };

    Sync(const Sync&) = delete;
    Sync(Sync&&);

    Sync(__SyncCondition condition = SyncCondition::GPUCommandsComplete); /*<
    Creates a new sync object for the specified [^condition].
    See [glfunc FenceSync].
    >*/

    bool Signaled() const; /*<
    Returns [^true] if this Sync object is in signaled state.
    See [glfunc GetSync], [glconst SYNC_STATUS], [glconst SIGNALED].
    >*/

    __SyncType Type() const; /*<
    Returns the type of this [^Sync] object.
    See [glfunc GetSync], [glconst OBJECT_TYPE].
    >*/

    __SyncCondition Condition() const; /*<
    Returns the condition of this [^Sync] object.
    See [glfunc GetSync], [glconst OBJECT_CONDITION].
    >*/

    __SyncStatus Status() const; /*<
    Returns the status of this [^Sync] object.
    See [glfunc GetSync], [glconst SYNC_STATUS].
    >*/

    __SyncWaitResult ClientWait(GLuint64 timeout) const; /*<
    Wait the specified number of nanoseconds or for the condition
    to be satisfied.
    See [glfunc ClientWaitSync].
    >*/

    void Wait(GLuint64 timeout) const; /*<
    Wait the specified number of nanoseconds or for the condition
    to be satisfied.
    See [glfunc WaitSync].
    >*/
    void Wait() const; /*<
    Wait indefinitely for the condition to be satisfied.
    See [glfunc WaitSync].
    >*/
};

//]
