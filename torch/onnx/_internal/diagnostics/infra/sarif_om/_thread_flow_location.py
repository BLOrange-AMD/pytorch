# DO NOT EDIT! This file was generated by jschema_to_python version 0.0.1.dev29,
# with extension for dataclasses and type annotation.

from __future__ import annotations

import dataclasses
from typing import Any


@dataclasses.dataclass
class ThreadFlowLocation(object):
    """A location visited by an analysis tool while simulating or monitoring the execution of a program."""

    execution_order: Any
    execution_time_utc: Any
    importance: Any
    index: Any
    kinds: Any
    location: Any
    module: Any
    nesting_level: Any
    properties: Any
    stack: Any
    state: Any
    taxa: Any
    web_request: Any
    web_response: Any


# flake8: noqa
