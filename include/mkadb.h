//
// Created by sparky on 5/21/23.
//

#ifndef MKADB_MKADB_H
#define MKADB_MKADB_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <vector>
#include <expected>

// creates flags out of indices
#define MKADB_FLAG(x) (1ul << x)

// mkadb - Kemalpaşa NoSQL embedded database project
// Copyright (c)2023 Yiğit Cemal Öztürk <admin@yigitovski.com>
// Licensed under GPLv3
namespace com {
    namespace yigitovski {
        namespace mkadb {
            /// Represents a table in a database
            typedef struct TableInfo {
                /// Represents a column in a table
                typedef struct ColumnInfo {
                    /// Represents the data type of a column
                    typedef enum class ColumnType {
                        /// Represents a null value
                        DB_NULL,
                        // String Types
                        STRING,
                        // Signed Integer Types
                        SINT8, SINT16, SINT32, SINT64, SINT128, SINT256,
                        // Unsigned Integer Types
                        UINT8, UINT16, UINT32, UINT64, UINT128, UINT256,

                        // Real Number Types
                        R_IEEE754_32, R_IEEE754_64, R_IEEE754_80,
                        // Binary Data Types
                        BLOB, BOOLEAN, BINARY,

                        // Date and Time
                        ISO8601, UNIX_TS
                    } ColumnType;
                    /// Represents properties of a column
                    typedef enum class ColumnFlags : u_int64_t {
                        NOT_NULL = MKADB_FLAG(1),
                        PRIMARY_KEY = MKADB_FLAG(2),
                        FOREIGN_KEY = MKADB_FLAG(3),
                        UNIQUE = MKADB_FLAG(4),
                        NULLABLE = MKADB_FLAG(5),
                        AUTO_INCREMENT = MKADB_FLAG(6),
                        DEFAULT = MKADB_FLAG(7),
                        INDEXED = MKADB_FLAG(8),
                        VIRTUAL = MKADB_FLAG(9),
                        STORED = MKADB_FLAG(10),
                        GENERATED = MKADB_FLAG(11),
                        HIDDEN = MKADB_FLAG(12),
                        READ_ONLY = MKADB_FLAG(13),
                        WRITE_ONLY = MKADB_FLAG(14),
                        READ_WRITE = MKADB_FLAG(15),
                        ENCRYPTED = MKADB_FLAG(16),
                        COMPRESSED = MKADB_FLAG(17),
                        DECRYPTED = MKADB_FLAG(18),
                        DECOMPRESSED = MKADB_FLAG(19),
                        SIGNED = MKADB_FLAG(20),
                        UNSIGNED = MKADB_FLAG(21),
                        ZEROFILL = MKADB_FLAG(22),
                        BINARY = MKADB_FLAG(23),
                        ENUM = MKADB_FLAG(24),
                    } ColumnFlags;
                    char *name;
                    ColumnType type;
                    ColumnFlags flags;
                    std::optional<uint32_t> length;
                } Column;

                char *name;
            } Table;
            /// Represents a Kemaplpaşa Database Instance
            class KemalpasaDB {
            public:
                KemalpasaDB();
                ~KemalpasaDB();
                /// Creates a table in this instance
                Table& createTable(Table tableInfo);
            };
        }
    }
}
#endif //MKADB_MKADB_H
