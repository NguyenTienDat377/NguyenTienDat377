# Hi, I'm Đạt 👋

Backend engineer based in Hanoi, Vietnam — I like systems that stay correct under concurrency, and I write down *why* a design decision was made, not just what it does.

Currently: Java/Spring Boot backend work, with a growing interest in constraint solving (Z3/SMT) applied to real developer tooling.

---

## 🔧 What I've built

### [abp — API Billing Platform](https://github.com/NguyenTienDat377/abp)
`Java` `Spring Boot` `Resilience4j` `Kafka` `RabbitMQ` `PostgreSQL` `Redis` `Docker`

A modular monolith for merchant API billing, split into 5 bounded contexts by data ownership rather than call patterns.

- Atomic `INSERT ... ON CONFLICT DO UPDATE` + DB-level unique constraints prevent lost updates and double-subscribes — no read-then-write races.
- Per-merchant Resilience4j bulkhead + circuit breaker, so one bad merchant can't starve every other tenant's requests.
- Redis cache-aside for merchant routing/pricing (read:write ratio ~10⁵), with a fail-open `CacheErrorHandler` — a Redis outage degrades gracefully instead of taking the gateway down.
- Dual messaging: RabbitMQ drives the operational write with queue-based load leveling; the same event is republished to Kafka (partitioned by `merchant_id`) as a durable, independently replayable audit log.
- UUIDv7 primary keys for B-tree write locality under high-volume inserts.
- Verified with dedicated k6 load tests and Testcontainers integration tests.

### [Skolem — Formal Verification for AI-Generated SQL](https://github.com/NguyenTienDat377/Skolem)
`Python` `FastAPI` `Z3/SMT` `Supabase` `Docker`

Given a DDL schema and two SQL queries, Skolem uses **Z3 SMT solving** to formally prove semantic equivalence — or produce the exact counterexample database where they diverge. Not linting, not heuristics: deterministic proof.

- **Three delivery surfaces, one engine**: a web UI for manual review, a CI/CD JSON endpoint for pipelines, and an **MCP server so AI coding agents (Claude Code, Cursor) call verification in-loop** — powering a counterexample-driven self-healing repair loop.
- Fail-closed encoding: any SQL outside the supported subset is rejected with an error rather than silently dropped (a dropped predicate could produce a false "equivalent").
- Witness cross-check: a `divergent` verdict is re-run against a concrete SQLite witness before being trusted, to catch encoder bugs rather than showing a fake counterexample.
- GitHub OAuth + magic-link auth, per-user API keys, Supabase/Postgres with RLS, billing via Lemon Squeezy (fails open on metering errors), circuit breaker on LLM calls.
- 7 test suites: smoke tests, regression tests from the [VeriEQL paper](https://github.com/NguyenTienDat377/Skolem/blob/master/docs/references/veriEQL-2024.pdf), and differential fuzzing against SQLite.

### [InstaClone](https://github.com/NguyenTienDat377/InstaClone)
`Java 21` `Spring Boot 3.5` `Spring Security` `Redis` `MySQL` `MinIO` `Docker`

An Instagram-style backend with a layered architecture (controller/service/repository) grouped by domain (auth, feed, profile).

- Google OAuth2 login via Spring Security with auto-provisioned users.
- Redis-backed distributed HTTP sessions (Spring Session) for horizontal scalability.
- MinIO (S3-compatible) object storage for image uploads.
- Centralized exception handling via `@RestControllerAdvice`, mapping domain exceptions to stable HTTP status codes.
- Full stack containerized with Docker Compose (MySQL, Redis, MinIO, backend), documented via auto-generated OpenAPI/Swagger.

### [go-api-gateway](https://github.com/NguyenTienDat377/go-api-gateway)
`Go` `SQLite`

A dynamic API gateway: SQLite-backed route table, matched by path/method/header, behind a thread-safe router (`sync.RWMutex`, concurrent reads under exclusive writes).

- Runtime admin API (`POST /admin/routes`) to register routes without a restart or touching SQL by hand.
- Two pluggable rate-limiting strategies (token bucket, fixed window) — defaults to token bucket to avoid the boundary-burst problem fixed windows allow at window edges.

### [LCHelper](https://github.com/NguyenTienDat377/LCHelper)
`Python` `discord.py` `PostgreSQL` `Redis`

Discord bot for **Lowie's LeetCode Community**, a 250-member university LeetCode practice club running since 2024.

- Contributed features: username-based profile lookup, submission embed rendering.
- Built on a SQLAlchemy-backed relational schema (problems, topics, missions) with a cogs-based command architecture.
- Collaborated through PR review cycles with teammates.
- I also contribute structured solution write-ups (approach, complexity analysis) to the club's daily-solutions channel by signing up for specific days.

---

## 🌱 Open Source

- **[resilience4j #2503](https://github.com/resilience4j/resilience4j/pull/2503)** — changed `BulkheadConfig`'s constructor visibility to `protected` to enable subclassing for custom metadata, with an added test.
- **[testcontainers-java #11964](https://github.com/testcontainers/testcontainers-java/pull/11964)** — self-identified and fixed a silent-null-return bug in `BrowserWebDriverContainer.getSeleniumAddress()`, replacing it with a fail-fast exception.
- **[google/highway #3248](https://github.com/google/highway/pull/3248)** *(merged)* — redesigned CI to run the full compiler matrix only on a weekly schedule instead of every PR, cutting CI jobs per pull request from 28 to 11.

---

## 🎓 Background

- B.S. Computer Science, VNU University of Engineering and Technology (2022 – 2026)
- Software Engineer Intern, NAB Innovation Center — Java Spring Boot, Kafka microservices, Jenkins/Snyk/Harness
- Semi-Finalist, Code Tour 2024 (VNG-organized competitive programming event)
- AWS Cloud Practitioner · Kaggle Bronze Medal · IELTS Overall 7.0 (C1)

## 📚 Academic / Research (Constraint Solving)

- **[AlienTile](https://github.com/NguyenTienDat377/AlienTile)** — Bachelor's Thesis: solver comparison for a tiling/coloring problem across CP-SAT, CPLEX (CP and ILP), and Gurobi.
- **[BoardPackagingSATConvert](https://github.com/NguyenTienDat377/BoardPackagingSATConvert)** — related earlier work on the Board Packing Problem: pseudo-Boolean SAT encoding in Java (at-most-one placement constraints, etc.).
- **[UniCorT](https://github.com/NguyenTienDat377/UniCorT)** — SAT/MaxSAT-based university course timetabling (Google OR-Tools CP-SAT), built on Alexander Lemos's UniCorT with constraints for room conflicts, day/time spacing, and precedence.

---

📫 [LinkedIn](https://www.linkedin.com/in/dat-nguyen-tien-2b734b21a/) · ntdat377@gmail.com
